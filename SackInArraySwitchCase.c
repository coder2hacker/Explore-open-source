#include<stdio.h>
#include<stdlib.h>
int MAX_SIZE=10;

struct stack{
	int a[10];
	int front,rear;
}st;

void create(struct stack* st)
{
	st->front=0;
	st->rear=-1;
}

void display(struct stack* st)
{   int i;
	printf("The stack is\n");
	for(i=st->front;i<=st->rear;i++)
	{
		printf("%d ",st->a[i]);
	}
	printf("\n");
}

void push(struct stack* st, int val)
{
    if(st->rear>-2&&st->rear<9)
    {   
	    st->rear++;
    	st->a[st->rear]=val;		
	}
	else{
      printf("OVERFLOW\n");
	}
}
void peek(struct stack* st)
{
	if(st->rear==-1)
	{
		printf("The stack is empty\n");
	}
	else
	{
		printf("The top element of the stack is: %d\n",st->a[st->rear]);
	}
}
void pop(struct stack* st)
{
	if(st->rear>0&&st->rear<10)
	{
	   st->rear--;	
	}
	else{
		printf("The stack is empty\n");
	}
}

int main()
{   int choice,val,itr=1;
printf("1 to create\n2 to push\n3 to pop\n4 to display\n5 to peek\n6 to exit\n\n");
    while(itr)
       { 
        printf("Enter the choice\n");
	    scanf("%d",&choice);
    	switch(choice)
    	{
    		case 1:
                create(&st);
    			break;
    		case 2:
    			printf("Enter the element to push\n");
    			scanf("%d",&val);
    			push(&st,val);
				break;
			case 3:
			    pop(&st);
				break;
		    case 4:
			    display(&st);
			    break;
			case 5:
			    peek(&st);
			    break;
			case 6:
			    itr=0;
			    break;			    
			default:
				printf("wrong case\n");
				break;
			
							
		}
	}

	return 0;
}
