#include<bits/stdc++.h>
using namespace std;

// A tree node
struct node
{
	int data;
	struct node *left;
	struct node *right;
	
	node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

// Returns maximum value in a given Binary Tree
int findMax(struct node* root);
// Returns minimum value in a given Binary Tree
int findMin(struct node* root);

void insert(struct node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->data==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new node(n2);
                    break;
          case 'R': root->right=new node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct node *root=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new node(n1);
            switch(lr){
                    case 'L': root->left=new node(n2);
                    break;
                    case 'R': root->right=new node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }

    cout<<findMax(root)<<" "<<findMin(root)<<endl;
    }
    return 0;
}
// } Driver Code Ends


// Returns maximum value in a given Binary Tree
int findMax(struct node* root)
{
// Your code goes here
    queue <node *> q;
    q.push(root);
    int m=INT_MIN;
    while(!q.empty())
    {
        int count=q.size(),sum=0;
        for(int i=0;i<count;i++)
        {
            node *cur=q.front();
            m=max(cur->data,m);
            q.pop();
            if(cur->left!=NULL)
                q.push(cur->left);
            if(cur->right!=NULL)
                q.push(cur->right);
        }
    }
    return m;
}

// Returns minimum value in a given Binary Tree
int findMin(struct node* root)
{
// Your code goes here
    queue <node *> q;
    q.push(root);
    int m=INT_MAX;
    while(!q.empty())
    {
        int count=q.size(),sum=0;
        for(int i=0;i<count;i++)
        {
            node *cur=q.front();
            m=min(cur->data,m);
            q.pop();
            if(cur->left!=NULL)
                q.push(cur->left);
            if(cur->right!=NULL)
                q.push(cur->right);
        }
    }
    return m;
}
