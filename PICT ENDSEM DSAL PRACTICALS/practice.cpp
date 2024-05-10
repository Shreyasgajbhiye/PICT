#include<iostream>
using namespace std;
class node{
    public:
    node* left;
    node* right;
    int data;
    bool rbit, lbit;

    node(){
        this->data = 0;
        this->rbit = 0;
        this->lbit = 0;
        this->left = NULL;
        this->right = NULL;
    }
    node(int data){
        this->data = data;
        this->rbit = 0;
        this->lbit = 0;
        this->left = NULL;
        this->right = NULL;
    }

    void print(){
        cout << this->lbit << "-> " << this->data << " <-" << this->rbit << endl;
    }

    friend class TBST;
};

class TBST{
    node* head, *root;
    public:
    TBST(){
        head = root = NULL;
    }

    void insert(int key){
        if(root==NULL){
            head = new node(-9999);
            head->right = head;

            root = new node(key);
            head->left = root;
            head->lbit = 1;
            root->left = head;
            root->right  = head;
            return;
        }

        node* parent  = root;
        node *newNode = new node(key);

        while(true){
            if(parent->data > key){
                if(parent->lbit == 1){
                parent = parent->left;
            }
            else{
                newNode->left = parent->left;
                newNode->right = parent;
                parent->left = newNode;
                parent->lbit = 1;
                return;
            }
            }
            else if(parent->data < key){
                if(parent->rbit == 1){
                    parent = parent->right;
                }
                else{
                    newNode->right = parent->right;
                    newNode->left = parent;

                    parent->right = newNode;
                    parent->rbit = 1;
                    return;
                }
            }
        }
    }

    void inorder(){
        node* temp = root;
        while(temp->lbit ==1){
            temp = temp->left;
        }

        while(temp!=head){
            temp->print();
            if(temp->rbit ==1 ){
                temp = temp->right;

                while(temp->lbit == 1){
                    temp = temp->left;
                }
            }
            else{
                temp = temp->right;
            }
        }
        cout << endl;
    }


    void preorder(){
        bool flag =0;
        node* temp = root;
        while(temp != head){
            if(flag == 0){
                temp->print();
            }
            if(flag == 0 && temp->lbit == 1){
                temp= temp->left;
            }
            else{
                flag = temp->rbit == 0 ? 1 : 0;
                temp = temp->right;
            }
        }
    }
};


int main()
{
    TBST obj;
    obj.insert(20);
    obj.insert(2);
    obj.insert(5);
    obj.insert(30);
    obj.inorder();
    obj.preorder();
    return 0;
}