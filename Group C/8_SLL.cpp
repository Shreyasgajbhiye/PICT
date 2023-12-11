#include<bits/stdc++.h>
using namespace std;
class SLL{
    public:
    char start[20];
    char end[20];
    char min[20];
    char max[20];
    bool status;
    SLL* next;
};
class Appoinment{
    public:
    SLL* createAppoinment(SLL *head);
    void display(SLL *head);
    void bookAppoinment(SLL *head);
    void deleteAppoinment(SLL *head);
};

SLL* Appoinment::createAppoinment(SLL *head){
    SLL* temp = head;
    SLL* newNode;
    int n;
    cout << "Enter the number of slots : \n";
    cin >> n;

    for(int i=0;i<n;i++){
        newNode = new SLL;
        cout << "Enter the start time : \n";
        cin >> newNode->start;
        cout << "Enter the end time : \n";
        cin >> newNode->end;
        strcpy(newNode->min,"1 hr");
        strcpy(newNode->max,"2 hr");
        newNode->status = false;
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            temp = head;
        }
        else{
            temp->next = newNode;
            temp = temp->next;
        }

        cout << "Slot craeted !!" << endl;
    }
    return head;
}

void Appoinment::display(SLL *head){
    SLL* temp = head;
    while(temp != NULL){
        cout << "\tStart time : " << temp->start ;
        cout << "\tEnd time : " << temp->end ;
        cout << "\tMin time : " << temp->min ;
        cout << "\tMax time : " << temp->max ;
        cout << "\tStatus  : " << temp->status << endl;
        
        temp = temp->next;
    }

}

void Appoinment::bookAppoinment(SLL *head){
    SLL *temp = head;
    char cn[20];
    cout << "ENTER THE START TIME : \n";
    cin >> cn;
    while(temp != NULL){
        if (strcmp(temp->start,cn)==0){
            if(temp->status){
                cout << "SLOT IS ALREADY BOOKED !! \n";
            }
            else{
                temp->status = true;
                cout << "SLOT BOOKED !!!" << endl;
                break;
            }
        }
        temp = temp->next;
    }

    if (temp==NULL){
        cout << "NO SLOT EXISTS !!" << endl;
    }
}
void Appoinment::deleteAppoinment(SLL *head){
    SLL *temp = head;
    char c[20];
    cout << "ENTER THE TIME : \n";
    cin >> c;
    while(temp!=NULL){
        if(strcmp(temp->start,c)==0){
            if(temp->status){
                temp->status  = false;
                cout << "SLOT DELETED !!\n";
            }
            else{
                cout << "ALREADY AVAILABE \n";
            }
        }
        temp = temp->next;
    }
}
int main()
{
    SLL *head=NULL;
    Appoinment a;
    head = a.createAppoinment(head);
    a.display(head);
    a.bookAppoinment(head);
    a.display(head);
    a.deleteAppoinment(head);
    a.display(head);
    return 0;
}