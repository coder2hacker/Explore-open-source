#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//Structure Declaration for Doubly linked list
typedef struct dlist
{
	struct dlist *pre;
	int info;
	struct dlist *next;
}node;

//prototype
node*insert_first(node*);
node*insert_last(node*);
node*del_first(node*);
node*del_last(node*);
void traverse(node*);

node*insert_after(node*);
node*del_any(node*);
node*insert_before(node*);

void rev_display(node*);

int count(node *);
void even(node *);
node * delete_first_nth(node *);
node * delete_last_nth(node *);
int main()
{
	int c,c1;
	node*H=NULL;
	while(1)
	{
		printf("\n------------------------------------------------------");
		printf("\n1.Insert First \n2.Insert Last \n3.Insert Before \n4.Insert After");
		printf("\n5.Delete First \n6.Delete Last \n7.Delete Any \n8.Display");
		printf("\n9.Reverse Display \n10.Total No of Nodes \n11.Even Number Display");
		printf("\n12.Delete 1st N-th Node");
		printf("\n13.Delete Last N-th Node");
		printf("\n0.Exit");
		
		printf("\nEnter your choice: ");
		
		scanf("%d",&c);
		switch(c)
		{
			case 1: H=insert_first(H);
				break;
			case 2:H=insert_last(H);
				break;	
			case 3:H=insert_before(H);
				break;
			case 4:H=insert_after(H);
				break;
			case 5:H=del_first(H);
				break;	
			case 6:H=del_last(H);
				break;	
			case 7:H=del_any(H);
				break;	
				
			case 8: traverse(H);
				break;
			case 9: rev_display(H);
				break;
			case 10: c1=count(H);
				printf("\nTotal No. of Nodes = %d",c1);
				break;
			case 11: even(H);
				break;
			case 12: H=delete_first_nth(H); 
				break;
			case 13: H=delete_last_nth(H);
				break;
			case 0: exit(0);
				break;
				
			default:printf("Worng Choice");											
		}
		
	}
	return 0;
}
node * delete_first_nth(node *H1)
{
	int val, node_no,i;
	node *p=H1;
	node_no=count(H1);
	printf("\nTotal Number of nodes present=%d",node_no);
	printf("\nHow many nodes you want to delete from the first? ");
	scanf("%d",&val);
	printf("\nYou Entered = %d", val);
	if(val>node_no || val<1)
		printf("\nINVALID INPUT... Check Once Again");
	else
	{
		printf("\nYes Possible");
		for(i=1;i<=val;i++)
		{
			H1=del_first(H1);		
		}
	}
	
	return H1;
}

node * delete_last_nth(node *H1)
{
	int val, node_no,i;
	node *p=H1;
	node_no=count(H1);
	printf("\nTotal Number of nodes present=%d",node_no);
	printf("\nHow many nodes you want to delete from the last? ");
	scanf("%d",&val);
	printf("\nYou Entered = %d", val);
	if(val>node_no || val<1)
		printf("\nINVALID INPUT... Check Once Again");
	else
	{
		printf("\nYes Possible");
		for(i=1;i<=val;i++)
		{
			H1=del_last(H1);		
		}
	}
	
	return H1;
}
int count(node *H1)
{
	node *p=H1;
	int c=0;
	if(H1==NULL)
		{
			printf("List is Empty\n");
			return 0;
		}
	while(p!=NULL)
	{
	c++;
	p=p->next;	
	}
	return c;
}
void even(node *H1)
{
	node *p=H1;
	if(H1==NULL)
		{
			printf("List is Empty\n");
			return;
		}
	while(p!=NULL)
	{
		if(p->info % 2==0)
			printf("\t%d",p->info);
	
		p=p->next;	
	}
	
}

node *insert_first(node *H1)
{
	node*p=H1;                      //NULL              
	H1=(node *)malloc(sizeof(node));
	H1->next=p;  //NULL  
	printf("Enter a value :");
	scanf("%d",&H1->info);
	//For DList
	H1->pre= NULL; 
	/* As the newly created node is our 1st node so, we need to set up NULL in its pre */
	if(p!=NULL)
		p->pre=H1; 
	/* Previous 1st node pre segment that was NULL will be replaced by the address of
	recent 1st node */
	
	return H1;
}
node *insert_last(node *H1)
{
	node *temp,*prev;
	int n;
	temp=(node *)malloc(sizeof(node));
	printf("Enter a value :");
	scanf("%d",&n);
	if(temp==NULL)
	{
		printf("\n Memory allocation unsucessful");
		return H1;
	}
	temp->info=n;
	temp->next=NULL;
	if(H1==NULL)
	{
		H1=temp;
		H1->pre=NULL;
		return H1;
	}
	prev=H1;
	while(prev->next!=NULL)
	{
		prev=prev->next;
	}
	prev->next=temp;
	temp->pre=prev;
	return H1;
}
node *del_first(node*H1)
{
	node*p=H1;
	if(H1==NULL)
	{
		printf("List is Empty.\n");
		return H1;
	}
	H1=H1->next;
	printf("\n%d is deleted.",p->info);
	free(p);
	if(H1!=NULL)
		H1->pre=NULL;
	return(H1);
}
node *del_last(node*H1)
{
	node*p=H1;
	node*p1=H1;
	if(H1==NULL)
	{
		printf("List is Empty\n");
		return H1;
	}
	if(H1->next == NULL)
	{
		H1=del_first(H1);
		return H1;
	}
	
	while(p->next!=NULL)
	{
		p1=p;
		p=p->next;
	}
	p1->next=NULL;
	printf("\n%d is deleted.",p->info);
	free(p);
	return(H1);
}
void traverse(node*H1)
{
	node *p=H1;
	if(H1==NULL)
		printf("List is Empty\n");
	while(p!=NULL)
	{
	printf(" %d\t",p->info);
	printf(" (%d)\t", p->next);
	p=p->next;	
	}
}
void rev_display(node*H1)
{
	if(H1==NULL)
	{
		return;
	}
	rev_display(H1->next);
	printf("%d\t",H1->info);
}
//Insert a node after a given node(Value)

node*insert_after(node*H1)
{
	int v;
	node *p,*p1,*new_node;
	p=p1=H1;
	printf("\nEnter value after which to be inserted: ");
	scanf("%d",&v);
	if(H1==NULL)
	{
		printf("List is Empty.\n");
		return H1;
	}
	while(p!=NULL && p->info!=v)
	{
		p=p->next;
			if(p==NULL)
		{
		printf("\nInvalid Input");
		return H1;
		}
	}
	if(p->next==NULL)
		{
			new_node=(node *)malloc(sizeof(node));
			printf("Enter the value: ");
			scanf("%d",&new_node->info);
			new_node->next=NULL;
			new_node->pre=p;
			p->next=new_node;
			
		}
	else
	{
			p1=p->next;
			new_node=(node *)malloc(sizeof(node));
			printf("Enter the value: ");
			scanf("%d",&new_node->info);
			p->next=new_node;
			new_node->pre=p;
			new_node->next=p1;
			p1->pre=new_node;
		
	}
	
	return H1;
}
//To insert a node before a given node(value)
node*insert_before(node*H1)
{
	int v;
	node*p,*p1,*newnode;
	p=p1=H1;
	if(H1==NULL)
	{
		printf("List is Empty.\n");
		return H1;
	}
	printf("\n Enter the value before which you want to insert: ");
	scanf("%d",&v);
	while(p != NULL && p->info!=v )
	{
		p1=p;
		p=p->next;
	}
	if(p==NULL)
	{
		printf("\n Invalid input\n");
		return H1;
	}
	else if(p==H1)
	{
		H1=insert_first(H1);
	}
	else
	{
		newnode=(node *)malloc(sizeof(node));
		printf("\nEnter a value: ");
		scanf("%d",&newnode->info);
		newnode->next=p;
		p1->next=newnode;
		newnode->pre=p->pre;
		p->pre=newnode;
		return H1;
	}
}

//To delete a any node of the linked list
node*del_any(node*H1)
{
	int v;
	node*p,*p1;
	p=p1=H1;
	
	
	if(H1==NULL)
	{
		printf("List is Empty.\n");
		return H1;
	}
	printf("\nInsert Value which you want to delete:");
	scanf("%d",&v);
	while(p!=NULL && p->info!=v)
	{
		p1=p;
		p=p->next;	
	}
	if(p==NULL)
	{
		printf("\nInvalid Input");
		return H1;	
	}
	else if(p==H1)
	{   H1=H1->next;
		free(p);
		return H1;
	}
	else
	{
		p1->next=p->next;
		printf("\n%d is deleted\t",p->info);
		free(p);
		return H1;
	}
	
}
