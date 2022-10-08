#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct list
{
	int info;
	struct list*next;
}node;


//prototype

node*insert(node*);
node*del_1_node(node*);
node*del_many_node(node*);
void display(node*);

// Main Function

int main()
{
	int ch,c1;
	node*H=NULL;
	while(1)
	{	
		printf("\n 1 Insert\n 2 Delete\n 3 Display\n 4 exit");
		printf("\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: H=insert(H);
				break;
			case 2: H=del_many_node(H);
				break;
			case 3: display(H);
				break;
			case 4: exit(0);
				break;
			default: printf("Worng Choice !!!");											
		}
	}
return 0;
}


node *insert(node*H1)
{
	node*p=H1;
	H1=(node*)malloc(sizeof(node));
	H1->next=p;
	printf("Enter a value :");
	scanf("%d",&H1->info);
	printf("\n%d is inserted.",H1->info);
	return(H1);
}

node *del_1_node(node*H1)
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
	return(H1);
}


node *del_many_node(node*H1)
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
		H1=del_1_node(H1);
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

void display(node*H1)
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
