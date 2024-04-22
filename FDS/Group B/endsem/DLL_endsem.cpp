#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;

    public:
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void InsertAtHead(Node* &head,int data){
    Node *newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void InsertAtTail(Node* &tail,int data){
    Node *newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void display(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp= temp->next;
    }
    cout << endl;
}

void InsertAtMiddle(Node* &head, Node* &tail, int pos, int data){
    if(pos==1){
        InsertAtHead(head,data);
        return;
    }
    Node* temp = head;
    if(temp == NULL){
        InsertAtTail(tail,data);
        return;
    }

    int cnt=1;
    while(cnt < pos-1){
        temp=temp->next;
        cnt++;
    }
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    newNode->next->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;
}

void deleteNode(Node* &head,int pos){
    if(pos==1){
        Node *temp = head;
        temp->next->prev = NULL;
        head = head->next;
        temp->next= NULL;
        delete temp;
    }

    Node *curr = head;
    Node *prev = NULL;
    int cnt = 1;
    while(cnt < pos){
        prev = curr;
        curr =curr->next;
        cnt++;
    }

    curr->prev = NULL;
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}
int main()
{
    Node *n = new Node(20);
    Node *head = n;
    Node *tail = n;
    InsertAtHead(head,10);
    InsertAtHead(head,5);
    InsertAtMiddle(head,tail,2,33);
    display(head);
    deleteNode(head,2);
    display(head);
    return 0;
}