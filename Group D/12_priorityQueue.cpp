#include<iostream>
using namespace std;
class Node{
    int pid;
    int priority;
    Node* next, *prev;

    friend class PQueue;
};
class PQueue{
    Node  *front=NULL, *rear=NULL;
    public:

        void enqueue(){
        Node *n = new Node;
        cout << "PID : \n";
        cin >> n->pid;
        cout << "PRIOR : \n";
        cin >> n->priority;
        n->next = NULL;
        n->prev = NULL;

        if(front == NULL && rear == NULL){
            front = n;
            rear = n;
        }
        else if(n->priority > front->priority){
            n->next = front;
            front->prev = n;
            front = n;
        }
        else if(n->priority < rear->priority){
            rear->next = n;
            n->prev = rear;
            rear = n;
        }
        else{
            Node *ptr=new Node;
            while(ptr->next != NULL){
                if(ptr->priority < n->priority){
                    break;
                }
                ptr = ptr->next;
            }
            n->next = ptr->next;
            ptr->next = n;
            n->prev = ptr;
        }
   }
    
    void display(){
        Node *ptr = this->front;
        while(ptr!=NULL){
            cout << "(" << ptr->pid << ", " << ptr->priority << ") -> ";
            ptr = ptr->next;
        }
    }

    void dequeue(){
        Node* ptr = front;
        front = front->next;
         cout << "Process Deleted : " << ptr->pid << endl;

        this->display();
    }

};
int main()
{
    PQueue *Q = new PQueue();

    Q->enqueue();
    Q->enqueue();
    Q->enqueue();
    Q->display();
    //Q->enqueue();
    // Q->dequeue();
    // Q->dequeue();
    return 0;
}