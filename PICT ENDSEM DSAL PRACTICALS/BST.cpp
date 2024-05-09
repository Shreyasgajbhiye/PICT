#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* right;
    node* left;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* createBST(node* &root, int data){
    if(root==NULL){
        root = new node(data);
        return root;
    }

    if(data > root->data){
        root->right = createBST(root->right, data);
    }
    else{
        root->left = createBST(root->left, data);
    }

    return root;
}

void takeInput(node* &root){
    int data;
    cout << "Enter the data: (-1 to stop)\n";
    cin >> data;

    while(data != -1){
        createBST(root, data);
        cin >> data;
    }
}

vector<int> inorder(node* &root){
    stack<node*> stk;
    node* temp = root;
    vector<int> v;
    while(true){
        if(temp!=NULL){
            stk.push(temp);
            temp = temp->left;
        }
        else{
            if(stk.empty() == true) break;
            temp = stk.top();
            stk.pop();
            v.push_back(temp->data);
            temp = temp->right;
        }
    }
    return v;
}

void searchInBST(node* root, int key ) {
    int comp=0;
    while(root!=NULL){
        comp++;

        if(root->data == key){
            cout << "Value : " << key << " found !! with comparsions : " << comp << endl; 
            return;
        }
        else if(root->data > key){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }

    cout << "Value " << key << " not found with " << comp << " comparisons.\n";
}

node* deleteNode(node* &root, int key){
    if(root == NULL) return NULL;
    
    if(root->data > key){
        root->left = deleteNode(root->left, key);
    }
    else if(root->data < key){
        root->right = deleteNode(root->right, key);
    }
    else {
        if(root->left == NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        
        node* temp = root->right;
        while(temp->left != NULL){
            temp = temp->left;
        }
        
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    node* root = NULL;
    takeInput(root);
    vector<int> v;
    v = inorder(root);
    for(int i=0;i<v.size();i++){
        cout << v[i] << " " ;
    }
    cout << endl;

    int key;
    cout << "Enter the value to delete: ";
    cin >> key;

    root = deleteNode(root, key);
    
    v = inorder(root);
    for(int i=0;i<v.size();i++){
        cout << v[i] << " " ;
    }
    cout << endl;

    return 0;
}
