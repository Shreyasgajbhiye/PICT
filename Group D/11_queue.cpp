#include<iostream>
using namespace std;
class Q{
    public:
    int queue[20];
    int front , rear ;
    int size;

    Q(){
        size = 10;
        for(int i=0;i<size;i++){
            queue[i] = 0;
            front = -1;
            rear = -1;
        }
    }

    int isFull(){
        if(rear == size-1){
            return 1;
        }
        else {
            return 0;
        }
    }

    int isEmpty(){
        if(front == rear){
            return 1;
        }
        else{
            return 0;
        }
    }

    void add_job(int val){
        if(!isFull()){
            rear++;
            queue[rear] = val;
            cout << "INSERTED !!" << endl;
        }
        else{
            cout << "OVERFLOW \n";
        }
    }

    void delete_job(){
        if(!isEmpty()){
            front++;
            queue[front] = 0;
            cout << "DELETED !! \n";
        }
        else{
            cout << "ALREADY EMPTY \n";
        }
    }

    show_queue(){
        for(int i=0;i<size;i++){
            cout << "[ " << queue[i] << " ]" ;
        }
        cout << endl;
    }
};
int main()
{
    Q a;
    a.show_queue();
    a.add_job(10);
    a.add_job(20);
    a.add_job(30);
    a.show_queue();
    a.delete_job();
    a.delete_job();
    a.show_queue();
    return 0;
}