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

struct Node* modifyTheList(struct Node *head);

void push(struct Node **head_ref, int new_data)
{
  struct Node* new_node = new Node(new_data);
  new_node->next = *head_ref;    
  *head_ref = new_node;
}

void printList(struct Node *head)
{
    if (!head)
        return;
   	while (head->next != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data << endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL;
		while(n--){
			int a;
			cin>>a;
			push(&head, a);
		}
		head = modifyTheList(head);
		printList(head);
	}
    return 0;
}

// } Driver Code Ends


/*Complete the function below
Node is as follows:
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
struct Node* modifyTheList(struct Node *head)
{
    //add code here.
    int a[100],i=0,count=0;
    Node *cur=head;
    while(cur!=NULL)
    {
        a[i++]=cur->data;
        cur=cur->next;
        count++;
    }
    int n=count-1;
    for(i=0;i<=n/2;i++)
    {
        if(i==n-i)
            break;
        a[i]=a[i]-a[n-i];
    }
    cur=head;
    i=0;
    while(cur!=NULL)
    {
        cur->data=a[i++];
        cur=cur->next;
    }
    return head;
}
