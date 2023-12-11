#include<iostream>
using namespace std;
class node{
    public:
    node *next;
    char data;
};
class stackADT{
    public:
    node* head;
        stackADT(){
            head = NULL;
        }

        bool isEmpty(){
            if (head == NULL){
                return true;
            }
            else{
                return false;
            }
        }

        void push(char v){
            node *temp = new node;
            if (temp == NULL){
                cout << "OVERFLOW ";
            }
            else{
                temp->data = v;
                temp->next = head;
                head = temp;
            }
        }

        char pop(){
            if(!isEmpty()){
                char ch = head->data;
                node* temp = head;
                head = head->next;
                delete temp;
                return ch;

            }
            return '\0';
        }
        char peek(){
            if(!isEmpty()){
                
                return head->data;
            }
            return '\0';
        }

};