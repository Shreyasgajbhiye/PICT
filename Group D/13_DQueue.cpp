#include<iostream>
using namespace std;
class Dequeue{
    public:
    int front,rear;
    int queue[5];
    int size = 5;
    Dequeue(){
        front = -1;
        rear = -1;
        for(int i=0;i<5;i++){
            queue[i] = 0;
        }
    }
    


    void insert_Rear(int val){
        if(rear < size){
            rear++;
            queue[rear] = val;
            cout << "Inserted !! \n";
        }
        else{
            cout << "Queue is full \n";
        }
    }

    void delete_Front(){
        if(front!=rear){
            front++;
            queue[front] = 0;
            cout << "Deleted !!\n";
        }
        else{
            cout << "Queue is empty\n";
        }
    }

    void insert_Front(int val){
        if(front != -1){
            queue[front] = val;
            front--;
            cout << "Inserted !! \n";
        }
        else{
            cout << "Queue is full \n";
        }
    }

    void delete_rear(){
        if(rear != front){
            queue[rear] = 0;
            cout << "Deleted !!\n";
            rear--;   
        }else{
            cout << "Queue is empty \n";
        }
    }

    void show(){
        for(int i=0;i<size;i++){
            cout << "| " << queue[i] << " |" ;
        }
        cout << endl;
    }
};
int main()
{
    Dequeue a;
    a.insert_Rear(10);
    a.insert_Rear(20);
    a.insert_Rear(30);
    a.insert_Rear(40);
    a.insert_Rear(50);
    a.show();
    a.delete_rear();
    a.show();
    a.delete_Front();
    a.show();
    a.insert_Front(30);
    a.show();
    a.delete_rear();
    a.show();
    return 0;
}