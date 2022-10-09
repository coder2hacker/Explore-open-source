/* Circular queue using array */
/* Data Structures Using C by UDIT AGARWAL */

   #include <stdio.h>
   #include <conio.h>
   #include <alloc.h>
   #include <stdlib.h>
   #define MAX 5

   int cqueue[MAX];
   int front = -1;
   int rear = -1;

   void main ( )
   {
   clrscr();
   void insert(),del(),display();
   int choice;
   while (1)
   {
   printf ("1.Insert\n");
   printf ("2.Delete\n");
   printf ("3.Display\n");
   printf ("4.Quit\n");
   printf ("Enter your choice :");
   scanf ("%d", &choice);
   switch(choice)
   {
   case 1 :
   insert( );
   break;
   case 2 :
   del( );
   break;
   case 3 :
   display( );
   break;
   case 4 :
   exit(1);
   default:
   printf("Wrong choice\n");
   }
   }
   }

  void insert( )
   {
   int item;
   if((front==0 && rear==MAX-1) || (front==rear+1))
   {
   printf("Queue is Overflow\n");
   return;
   }
   if (front==-1)/*If queue is empty*/
   {
   front = 0;
   rear = 0;
   }
   else
   if (rear==MAX-1) /*rear is at last position of queue*/
   rear = 0;
   else
   rear = rear + 1;
   printf("Input the element for insertion :");
   scanf("%d", &item);
   cqueue[rear] = item;
   }

  void del( )
   {
   if (front == -1)
   {
   printf("Queue Underflow\n");
   return;
   }
   printf ("Deleted element from queue is : %d\n", cqueue[front]);
   if(front == rear)
   /* queue has only one element */
   {
   front = -1;
   rear = -1;
   }
   else
   if(front==MAX-1)
   front = 0;
   else
   front = front + 1;
   }

  void display( )
   {
   int front_pos = front, rear_pos = rear;
   if(front == -1)
   {
   printf("Queue is empty\n");
   return;
   }
   printf ("Queue elements are:\n");
   if(front_pos <= rear_pos)
   while(front_pos <= rear_pos)
   {
   printf(" %d\n", cqueue[front_pos]);
   front_pos++;
   }
   else
   {
   while(front_pos <= MAX-1)
   {
   printf(" %d\n", cqueue[front_pos]);
   front_pos++;
   }
   front_pos = 0;
   while(front_pos <= rear_pos)
   {
   printf(" %d\n", cqueue[front_pos]);
   front_pos++;
   }
   }
   printf("\n");
   }
