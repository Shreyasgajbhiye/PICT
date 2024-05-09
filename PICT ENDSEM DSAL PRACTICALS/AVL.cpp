#include<iostream>
using namespace std;
class Node
{
    public:
    int data,height;
    Node *lchild,*rchild;
};
class AVLTree{
    public:
    Node *root=NULL;
    Node* insert(Node* p,int key);
    int NodeHeight(Node *p);
    Node* LLRotation(Node* p);
    Node* RRRotation(Node* p);
    Node* LRRotation(Node *p);
    Node* RLRotation(Node* p);
    int BalanceFactor(Node* p);
    void inorder(Node* root);
};
int AVLTree::NodeHeight(Node *p)
{
    if (p == NULL)
        return 0;
    
    int hl = p->lchild ? p->lchild->height : 0;
    int hr = p->rchild ? p->rchild->height : 0;
    
    return (hl > hr ? hl : hr) + 1;
}

Node *AVLTree::LLRotation(Node *p)
{
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    pl->rchild=p;
    p->lchild=plr;

    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    if(root==p){
        root = pl;
    }

    return pl;
}

Node *AVLTree::LRRotation(Node *p)
{
    Node* pl=p->lchild;
    Node* plr=pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;

    plr->lchild=pl;
    plr->rchild=p;

    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    plr->height=NodeHeight(plr);

    if(p==root)
        root=plr;

    return plr;
}
Node *AVLTree::RRRotation(Node *p)
{
    Node* pr=p->rchild;
    Node* prl=pr->lchild;

    pr->lchild=p;
    p->rchild=prl;

    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    if(root==p)
    {
        root=pr;
    }
    return pr;
}

Node *AVLTree::RLRotation(Node *p)
{
    Node* pr=p->rchild;
    Node* prl=pr->lchild;

    p->rchild=prl->lchild;
    pr->lchild=prl->rchild;

    prl->lchild=p;
    prl->rchild=pr;

    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    prl->height=NodeHeight(prl);

    if(p==root)
        root=prl;
    return prl;
}
int AVLTree::BalanceFactor(Node *p)
{
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;
    return hl-hr;
}
void AVLTree::inorder(Node *p)
{
    if(p!=NULL)
    {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}
Node *AVLTree::insert(Node *p, int key)
{
    Node *t;
    if(p==NULL)
    {
        t=new Node;
        t->data=key;
        t->lchild=t->rchild=NULL;
        t->height=1;
        return t;
    }

    if(key>p->data)
    {
        p->rchild=insert(p->rchild,key);
    }
    else if(key<p->data)
    {
        p->lchild=insert(p->lchild,key);
    }
    //IMP
    p->height=NodeHeight(p);

    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
        return LLRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
        return LRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
        return RLRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
        return RRRotation(p);
    return p;    
}

int main()
{
    AVLTree obj;
    obj.root=obj.insert(obj.root,10);
    obj.insert(obj.root,5);
    obj.insert(obj.root,2);
    obj.inorder(obj.root);
    cout<<"\nRR: ";
    AVLTree trr;
    trr.root = trr.insert(trr.root, 10);
    trr.root = trr.insert(trr.root, 20);
    trr.root = trr.insert(trr.root, 30);
 
    trr.inorder(trr.root);
    cout << endl;
    return 0;
}