#include<iostream>
using namespace std;
class DLLNode{
    public:
    int bit;
    DLLNode *prev, *next;

    DLLNode *createNode(DLLNode *head);
    void display(DLLNode *head);
    void addition(DLLNode *head1, DLLNode *head2);
    void compliment_1(DLLNode *head);
    void compliment_2(DLLNode *head);
};
DLLNode* DLLNode::createNode(DLLNode *head){
    DLLNode *temp,*newNode;


    int i,size=4;
    for (i=0;i<size;i++){
    newNode = new DLLNode;
        cout << "Enter the bit 0/1 : \n";

        cin>>newNode->bit;
            newNode->prev = NULL;
            newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            temp = head;
        }
        else{
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
        cout << "Bit inserted !!\n";
    }

    return head;
}

void DLLNode::display(DLLNode *Head)
{
    DLLNode *temp;

    cout<<"\n\n\t Head->";
    temp = Head;
    while(temp != NULL)
    {
        cout<<"->|"<<temp->bit<<"|<-";
        temp = temp->next;
    }
}

void  DLLNode::addition(DLLNode *head1, DLLNode *head2){
    DLLNode *temp1, *temp2;
  bool carry = false; 

  temp1 = head1; 
  while(temp1->next != NULL)
    temp1 = temp1->next;

  temp2 = head2;
  while(temp2->next != NULL)
    temp2 = temp2->next;

  while (temp1 != NULL && temp2 != NULL) {
    int sum = temp1->bit + temp2->bit + carry; 
    temp1->bit = sum % 2; 
    carry = sum > 1; 
    temp1 = temp1->prev;
    temp2 = temp2->prev;
  }

  display(head1);

}

void DLLNode::compliment_1(DLLNode *head){
    DLLNode *temp;
    temp = head;
    while(temp != NULL){
        if(temp->bit==1){
            temp->bit = 0;
        }
        else{
            temp->bit =1;
        }
        temp = temp->next;
    }

    display(head);

    temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    while(temp->bit==1){
        temp->bit = 0;
        temp = temp->prev;
    }
    temp->bit = 1;
    display(head);

}

void DLLNode::compliment_2(DLLNode *head){
    DLLNode *temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    while(temp->bit==1){
        temp->bit = 0;
        temp = temp->prev;
    }
    temp->bit = 1;
    display(head);

    // while(temp->next != NULL)
    //         temp = temp->next;

    //     while(temp->bit == 1)
    //     {
    //         temp->bit = 0;
    //         temp = temp->prev;
    //     }
    //     temp->bit = 1;

    //     cout<<"\n\n 2's Compliment:";
    //     display_DLL(Head);
}
int main()
{
    DLLNode *head1 = NULL;
    DLLNode *head2 = NULL;
    DLLNode a;
    head1 = a.createNode(head1);
    head2 = a.createNode(head2);
    //a.display(head1);
    // a.display(head2);
    // a.addition(head1,head2);
    a.compliment_1(head1);
    return 0;
}