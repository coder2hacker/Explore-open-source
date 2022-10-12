#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node *sortedInsert(struct Node *head, int data);

void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
        
		int data;
		cin>>data;
		
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		
		int k;
		cin>>k;
		
		head = sortedInsert(head,k);
		printList(head); 
	}
	return 0; 
} 
// } Driver Code Ends


/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

// Should return head of the modified linked list
Node *sortedInsert(struct Node* head, int data) {
    // Code here
    Node *cur=head,*temp=new Node(data),*cur2;
    if(head->data>=data)
    {
        temp->next=head;
        head=temp;
        return temp;
    }
    bool val=false;
    while(cur->next!=NULL)
    {
        if(cur->next->data>=data)
        {
            cur2=cur->next;
            cur->next=temp;
            temp->next=cur2;
            val=!val;
            return head;
        }
        cur=cur->next;
    }
    if(val==false)
        cur->next=temp;
    
    
    return head;
}
