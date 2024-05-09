// // Beginning with an empty binary tree, construct binary tree by inserting the values in the
// // order given. After constructing a binary tree perform following operations on it-
// // • Perform preorder recursive traversal
// // • Postorder, Inorder non-recursive traversal
// // • Count number of leaves, number of internal nodes. 

// #include<bits/stdc++.h>
// using namespace std;
// class node{
//     public:
//     int data;
//     node* left;
//     node* right;
//     node(int data){
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

// node* createTree(node* root){
//     int data;
//     cout << "Enter the data : " << endl;
//     cin >> data;

//     if(data == -1){
//         return NULL;
//     }
//     root = new node(data);

//     cout << "Enter the left of " << data << " : " << endl;
//     root->left = createTree(root->left);
//     cout << "Enter the right of " << data << " : " << endl;
//     root->right = createTree(root->right);


//     return root;
// }


// void inorder(node* root){
//     if(root == NULL){
//         return;
//     }

//     inorder(root->left);
//     cout << root->data << " " ;
//     inorder(root->right);
// }
// void preorder(node* root){
//     if(root == NULL){
//         return;
//     }

//     cout << root->data << " " ;
//     preorder(root->left);
//     preorder(root->right);
// }
// void postorder(node* root){
//     if(root == NULL){
//         return;
//     }

//     postorder(root->left);
//     postorder(root->right);
//     cout << root->data << " " ;
// }

// vector<int> inorderNonRecursive(node* root){
//     stack <node*> stk;
//     vector<int> v;
//     node* temp = root;
//     while(true){
//         if(temp!=NULL){
//             stk.push(temp);
//             temp = temp->left;
//         }
//         else{
//             if(stk.empty() == true) break;
//             temp = stk.top();
//             stk.pop();
//             v.push_back(temp->data);
//             temp = temp->right;
//         }
//     } 
//     return v;
// }


// vector<int> preOrderNonRecursive(node* root){
//     vector<int> v;
//     stack <node*> stk;
//     node* temp = root;
//     stk.push(temp);
//     while(!stk.empty()){
//         temp = stk.top();
//         stk.pop();
//         v.push_back(temp->data);

//         if(temp->right) stk.push(temp->right);
//         if(temp->left) stk.push(temp->left);
//     }
//     return v;
// }

// vector<int> postOrderNonRecursive(node* root){
//     stack <node*> stk1;
//     stack <node*> stk;
//     node* temp = root;
//     vector<int> v;
//     stk.push(temp);

//     while(!stk.empty()){
//         root = stk.top();
//         stk.pop();
//         stk1.push(root);

//         if(root->left) stk.push(root->left);
//         if(root->right) stk.push(root->right);
//     }

//     while(!stk1.empty()){
//         v.push_back(stk1.top()->data);
//         stk1.pop();
//     }

//     return v;
// }
// int main()
// {
//     node* root = NULL;
//     root = createTree(root);
//     cout << "Inorder : \n";
//     vector<int> v ;
//     v= postOrderNonRecursive(root);
//     for(int i=0;i<v.size();i++){
//         cout << v[i] << " " ;
//     }


// }


#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
node* createTree(node* root){
    int data;
    cout << "Enter the value : " << endl;
    cin >> data;
    if(data == -1){
        return NULL;
    }
    root = new node(data);

    cout << "Enter the left od " << data << " : " << endl;
    root->left = createTree(root->left);
    cout << "Enter the right od " << data << " : " << endl;
    root->right = createTree(root->right);

    return root;
}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " " ;
    inorder(root->right);
}


vector<int> inorderNon(node* root){
    vector<int> v;
    stack<node*> stk;
    node* temp = root;
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

vector<int> preorderNon(node* root){
    stack <node*> stk;
    vector <int> v;
    node* temp = root;
    stk.push(temp);
    while(!stk.empty()){
        temp = stk.top();
        stk.pop();

        v.push_back(temp->data);

        if(temp->right) stk.push(temp->right);
        if(temp->left) stk.push(temp->left);
    }

    return v;
}

vector<int> postorderNon(node* root){
    stack <node*> stk;
    stack <node*> stk1;
    vector <int> v;
    node* temp = root;
    stk.push(temp);
    while(!stk.empty()){
        temp = stk.top();
        stk.pop();
        stk1.push(temp);

        if(temp->left) stk.push(temp->left);
        if(temp->right) stk.push(temp->right);
    }

    while(!stk1.empty()){
        node* temp1;
        temp1= stk1.top();
        stk1.pop();
        v.push_back(temp1->data);
    }

    return v;
}

void levelWise(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
    node* temp = q.front();
    q.pop();
    if(temp == NULL){
        cout << endl;
        if(!q.empty()) {
            q.push(NULL);
        }
    }    

    else{
        cout << temp->data << " ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    }

}

int height(node* root){
    if(root==NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right)+1;
    return ans;
}

int Nonleaf(node* root){
    if(root== NULL){
        return 0;
    }

    if(root->left == NULL && root->right == NULL) return 0;

    return 1 + Nonleaf(root->left) + Nonleaf(root->right);
}
int leaf(node* root){
    if(root== NULL){
        return 0;
    }

    if(root->left == NULL && root->right == NULL) return 1;

    return leaf(root->left) + leaf(root->right);
}


node* swapedTree(node* root){
    stack<node*> stk;
    stk.push(root);
    while(!stk.empty()){
        node* temp = stk.top();
        stk.pop();

        if(temp != NULL){
            stk.push(temp->left);
            stk.push(temp->left);
            swap(temp->left, temp->right);
        }
    }
    return root;
}

int main()
{
    node* root = NULL;
    root = createTree(root);
    // vector<int> v ;
    // v= postorderNon(root);
    // for(int i=0;i<v.size();i++){
    //     cout << v[i] << " " ;
    // }
    inorder(root);
    //swapedTree(root);
    //inorder(root);

    return 0;
}