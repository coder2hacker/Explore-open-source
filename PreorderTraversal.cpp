#include <iostream>
using namespace std;

struct node
{
    int data;
    node *lc;
    node *rc;
};

struct que 
{
    int status;
    node *ptr;
    que *next;
};
struct que *first=NULL;
struct que *last=NULL;

node *insert(int x,node *root)
{
    node *temp=new node;
    que *q=new que;
    temp->data=x;
    temp->lc=NULL;
    temp->rc=NULL;
    q->status=0;
    q->next=NULL;
    
    if(root==NULL)
    {
        q->ptr=temp;
        first=last=q;
        return temp;
    }
    else
    {
        if(first->status==0)
        {
            first->ptr->lc=temp;
            first->status=1;
        }
        else
        {
            first->ptr->rc=temp;
            first=first->next;
        }
        last->next = q;
        q->ptr = temp;
        last = q;
    }
    return root;
}
void preorder(node *root)
{
    if(root == NULL)
    return;
    else
    {
        preorder(root->lc);
        cout<<root->data<<" ";
        preorder(root->rc);
    }
}
int main()
{
    node *root = NULL;
    int ht;
    cout<<"Tree Elements in Array Form : ";
    for(int i = 0; i < 10; i++)
    {
        cout<<i<<" ";
        root = insert(i,root);
    }
    cout<<"\nPreorder Traversal : ";
    preorder(root);
    return 0;
}
