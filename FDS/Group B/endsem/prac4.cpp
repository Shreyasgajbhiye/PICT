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
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};

void InsertAtHead(Node* &head,int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}
void InsertAtTail(Node* &tail,int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void display(Node *head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void InsertAtMiddle(Node* head, Node*tail, int position,int data){
    if(position==1){
        InsertAtHead(head,data);
        return;
    }
    Node* temp = head;
    if(temp == NULL){
        InsertAtTail(tail,data);
        return;
    }

    Node *curr;
    int cnt=1;
    while(cnt < position-1){
        temp=temp->next;
        cnt++;
    }
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(Node* &head , int pos){
    if(pos==1){
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while(cnt < pos){
            prev = curr;
            curr = curr->next;
            cnt ++;
        }

        prev->next= curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *n1 = new Node(10);
    Node *head1 = n1;
    Node *tail = n1;
    InsertAtHead(head1,20);
    InsertAtTail(tail,20);
    InsertAtMiddle(head1,tail,2,21);
  
    display(head1);
    deleteNode(head1,1);
    display(head1);
    return 0;
}