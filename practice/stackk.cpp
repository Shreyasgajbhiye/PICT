#include<iostream>
using namespace std;
class Node{
    char data;
    Node *next;
};
class stackADT{
    Node* head;
    stackADT(){
        head = NULL;
    }

    bool isEmpty(){
        if(head==NULL){
            return true;
        }
        return false;
    }

    void push(char ch){
        Node * temp = new Node;
        if(temp == NULL){
            cout << "OVERLOW";
        }
        temp->data = ch;
        temp->next = head;
        head= temp;
    }

    char pop(){
        Node *temp;
        char ch = head->data;
        temp = head;
        head = head->next;
        delete temp;
        return ch;
    }

    char peek(){
        return head->data;
    }
};