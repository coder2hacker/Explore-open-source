//Program by Swaraj Shelavale @errorless111

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string data;
    Node* next;
    
    Node(string x){
        data = x;
        next = NULL;
    }
};

Node *newNode(string str)
{
    Node *new_node = new Node(str);
    new_node->next = NULL;
    return new_node;
}

bool compute(struct Node* root);

void print(Node *root)
{
    Node *temp = root;
    
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
                struct Node *temp = head;
		
		for(int i=0;i<K;i++){
		string str="";
		cin>>str;
			if(head==NULL)
			head=temp=new Node(str);
			else
			{
				temp->next = new Node(str);
				temp=temp->next;
			}
		}
		if(compute(head))
			cout<<"True"<<endl;
		else 
			cout<<"False"<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure of linked list is the following
struct Node
{
    string data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
#include <bits/stdc++.h>
bool compute(Node* root)
{
   //Your code goes here
   Node *cur=root,*last=root;
   stack<string> s;
   while(last!=NULL)
   {
       s.push(last->data);
       last=last->next;
   }
   while(cur!=NULL)
   {
       if(s.top()==cur->data)
       {
           s.pop();
           cur=cur->next;
           
       }
       else
            return 0;
   }
   return 1;
   
}
