#include <iostream>
using namespace std;
struct node
{
    char data;
    node *next;
};
class stackADT
{
public:
    node *head;
    stackADT()
    {
        head = NULL;
    }

    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }

    void push(char v)
    {
        node *temp = new node();
        if (temp == NULL)
        {
            cout << "Overflow" << endl;
            return;
        }
        temp->data = v;
        temp->next = head;
        head = temp;
        // cout << "Element inserted: " << v << endl;
    }
       char pop() {
        if (!isEmpty()) {
            char x = head->data;
            node* temp = head;
            head = head->next;
            delete temp;
            return x;
        }
        cout << "Stack is empty" << endl;
        return '\0';
    }

    char pop1(){
        char x;
        if(!isEmpty()){
            node* temp=head;
            x=temp->data;
            delete temp;
            return x;
        }
        cout << "Stack is empty" << endl;
        return '\0';

    }
    void display()
    {
        node *current = head;
        while (current != NULL)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }

    char peek() {
        if (!isEmpty()) {
            return head->data;
        }
        cout << "Stack is empty" << endl;
        return '\0';
    }
    
};