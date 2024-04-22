#include<iostream>
using namespace std;
class Q{
    public:
    int queue[20];
    int rear ,front;
    int size;
    Q(){
        size=5;
        for (int i =0;i<size;i++){
            queue[i] = 0;
        }
        rear = -1;
        front = -1;
    }

    void insertRear(int x){
        if(rear != size-1){
            rear++;
            queue[rear] = x;
            cout << "INserted \n";
        }
    }
    void insertFront(int x){
        if(front != -1){
            queue[front] = x;
            front--;
            cout << "INserted \n";
        }
    }

    void deleteFront(){
        if(front!=rear){
            front++;
            queue[front] = 0;
            cout << "Deleted\n";
        }
    }
    void deleteRear(){
        if(rear!=front){
            queue[rear] = 0;
            rear--;
            cout << "Deleted\n";
        }
    }
    void display(){
        for (int i=0;i<size;i++){
            cout << queue[i] << " | ";
        }
        cout << endl;
    }
};
int main()
{
    Q a;
    a.insertRear(10);
    a.insertRear(20);
    a.insertRear(30);
    a.insertRear(40);
    a.insertRear(50);
    a.display();
    a.deleteFront();
    a.display();
    a.insertFront(40);
    a.display();
    a.deleteRear();
    a.display();
    return 0;
}