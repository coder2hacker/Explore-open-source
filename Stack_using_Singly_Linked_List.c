#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct list
{
	int info;
	struct list*next;
}node;

//prototype

node*push(node*);
node*pop(node*);
void display(node*);

// Main Function

int main()
{
	int ch,c1;
	node*H=NULL;
	while(1)
	{	
		printf("\n 1 Push\n 2 Pop\n 3 Display\n 4 exit");
		printf("\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: H=push(H);
				break;
			case 2: H=pop(H);
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


node *push(node*H1)
{
	node*p=H1;
	H1=(node*)malloc(sizeof(node));
	H1->next=p;
	printf("Enter a value :");
	scanf("%d",&H1->info);
	printf("\n%d is inserted.",H1->info);
	return(H1);
}


node *pop(node*H1)
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