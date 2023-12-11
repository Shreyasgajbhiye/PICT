#include<iostream>
using namespace std;
class node{
    int priority=-1,pid=-1;
    node *next = NULL, *prev=NULL;
    friend class PQueue;
};
class PQueue{
    node* front=NULL, *rear=NULL;
    public:
    void enqueue(){
        node *n = new node;

        cout << "PID : \n";
        cin >> n->pid;
        cout << "Priority : \n";
        cin >> n->priority;
        n->next = NULL;
        n->prev = NULL;

        if(front == NULL && rear == NULL){
            front = n;
            rear = n;
        }
        else if(n->priority > front->priority){
            front->prev= n;
            n->next = front;
            front = n;
        }
        else if(n->priority < rear->priority){
            rear->next = n;
            n->prev = rear;
            rear = n;
        }
        else{
            node *ptr = this->front;
            while(ptr->next != NULL){
                if(ptr->priority < n->priority){
                    break;
                }
                ptr= ptr->next;
            }
            n->next = ptr->next;
            ptr->next = n;
            n->prev = ptr;
        }
        this->display();
    }

    void display(){
        node* ptr = this->front;
        while(ptr!=NULL){
            cout << "(" << ptr->pid << ", " << ptr->priority << ") -> ";
            ptr = ptr->next;
        }
    }
};
int main()
{
    PQueue *Q = new PQueue;
    Q->enqueue();
    Q->enqueue();
    Q->enqueue();
    Q->enqueue();
    //Q->display();
    return 0;
}

echo "# pict-sem-3" >> README.md
  git init
  git add README.md
  git branch -M main
  git remote add origin https://github.com/Shreyasgajbhiye/pict-sem-3.git
  git push -u origin main