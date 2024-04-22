#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next!= NULL){
            delete next;
            this->next = NULL;
        }
    }
};

void InsertAtHead(Node* &head, int data){
    Node *temp = new Node(data);
    temp->next= head;
    head = temp;
}

void InsertAtTail(Node* &tail, int data){
    Node *newNode = new Node(data);
    tail->next= newNode;
    tail = newNode;
}

void InsertAtMiddle(Node* &head,Node* &tail, int position, int data){
    if(position ==1){
        InsertAtHead(head,data);
        return;
    }
    
    Node *temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }
    if(temp == NULL){
        InsertAtTail(tail,data);
        return;
    }
    Node *newNode = new Node(data);

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(Node* &head,int position){
    if(position==1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    Node* curr = head;
    Node *prev = NULL;
    int cnt =1 ;
    while(cnt < position){
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}
void display(Node* head){
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main()
{
    Node *n1 = new Node(10);
    Node *head1 = n1;
    Node *tail = n1;
    InsertAtHead(head1,20);
    display(head1);
    deleteNode(head1,2);
    display(head1);
    return 0;
}