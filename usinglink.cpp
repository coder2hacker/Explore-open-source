/* Program to implement queue using Linked list */
/* Data Structures Using C by UDIT AGARWAL */

#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <stdlib.h>

struct node
{
int info;
struct node *link;
};
struct node *front, *rear;

void main ( )
{
	clrscr();
	void insert(),delet(),display();
	int ch;
	while (1)
	{
	printf ("1. Insert\n");
	printf ("2. Delete\n");
	printf ("3. Display\n");
	printf ("4. Exit\n");
	printf ("Enter your choice :");
	scanf ("%d", &ch);
	switch (ch)
	{
	case 1 :
	insert ( );
	break;
	case 2 :
	delet( );
	break;
	case 3 :
	display ( );
	break;
	case 4 :
	exit(0);
	default:
	printf ("Please enter correct choice \n");
	}
	}
	getch();
    }

void insert ( )
{
struct node *ptr;
ptr = (struct node*) malloc (sizeof (struct node));
int item;
printf ("Input the element for inserting :\n");
scanf ("%d", &item);
ptr-> info = item;
ptr->link = NULL;
if (front==NULL) /* queue is empty*/
front = ptr;
else
rear->link = ptr;
rear = ptr;
}

void delet( )
{
struct node *ptr;
if (front==NULL)
{
printf ("Queue is underflow \n");
return;
}
if (front==rear)
{
free (front);
rear = NULL;
}
else
{
ptr = front;
front = ptr->link;
free (ptr);
}
}

void display ( )
{
struct node *ptr;
ptr = front;
if (front==NULL)
printf("Queue is empty\n");
else
{
printf("\nElements in the Queue are:\n");
while(ptr!=NULL)
{
printf(" %d\n",ptr->info);
ptr=ptr->link;
}
printf("\n");
}
}
