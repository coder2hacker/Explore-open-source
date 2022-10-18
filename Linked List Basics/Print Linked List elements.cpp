#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*start;

void insert();
void display(Node *head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      start=NULL;
      insert();
      display(start);
      cout<<endl;
    }
    return 0;

}


 void insert()
 {
     int n,value;
     cin>>n;
     struct Node *temp;
     for(int i=0;i<n;i++)
     {
         cin>>value;
         if(i==0)
         {
              start=(struct Node *) malloc( sizeof(struct Node) );
              start->data=value;
              start->next=NULL;
              temp=start;
              continue;
         }
         else
         {
             temp->next= (struct Node *) malloc( sizeof(struct Node) );
             temp=temp->next;
             temp->data=value;
             temp->next=NULL;
         }
     }
 }

// } Driver Code Ends


/*
  Print elements of a linked list on console 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     Node *next;
  }
*/
void display(Node *head)
{
  //your code goes here
  Node *cur=head;
  while(cur!=NULL)
  {
      cout<<cur->data<<" ";
      cur=cur->next;
  }
}
