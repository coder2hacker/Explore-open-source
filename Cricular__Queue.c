#include<stdio.h>
#define max 5
#include<stdlib.h>

/* Structure definition*/
typedef struct circular_queue
{
	int a[max];
	int rear,front;
	
}queue;

/* Function type */
void insert(queue *p, int n);
void del(queue *p);
void display(queue *p);

int main()
{
	int x,m;
	queue q;
	q.rear=q.front=-1;
	while(1)
	{
		printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
		printf("\n Enter your choice:");
		scanf("%d",&x);
		
		switch(x)
		{
			case 1: printf("\n Enter a number:");
					scanf("%d",&m);
					insert(&q,m);
					break;
			case 2: del(&q);
					break;
			case 3: display(&q);
					break;
			case 4: exit(0);
			default: printf("\n Try again");
			
		}
	}
return 0;

}

void insert(queue *p, int x)
{
	if((p->rear+1)%max==p->front)
	{
		printf("\n Overflow");
		printf("\n Front =%d",p->front);
		printf("\n Rear=%d",p->rear);
		return;
	}
	/*when the first time insertion when the queue was empty*/
	else if(p->rear == -1 && p->front==-1)
	{
		p->front= p->rear=0;
		p->a[p->rear]=x;	
	}
	
	else if(p->rear ==max-1 && p->front!=0)
	{
		p->rear=0;
		p->a[p->rear]=x;
	}
	else
	{
		p->rear++;
		p->a[p->rear]=x;
		
	}
	
	/*else
	{
		p->rear=(p->rear+1)%max;
		(4+1)%5=0
		(0+1)%5=1
		(1+1)%5=2
		(2+1)%5=3
		(3+1)%5=4
		p->a[p->rear]=x;
	}*/
	printf("\n Front =%d",p->front);
	printf("\n Rear=%d",p->rear);
	printf("\n Value added");
}

void del(queue *p)
{
	int x;
	if(p->front==-1 && p->rear ==-1)
	{
		printf("\n Underflow");
		printf("\n Front =%d",p->front);
		printf("\n Rear=%d",p->rear);
		return;
	}
	else
	{
		//Elements will be deleted from front//
		x=p->a[p->front]; //deleted elements is stored in x
		if(p->front==p->rear) // here is only one element in circular queue//
		{
			p->front= p->rear=-1;	//c queue empty
		}	
		else
		{
			if(p->front==max-1)
				p->front=0;
			else
				p->front++;
			
		}
		
	}
	printf("\n Front =%d",p->front);
	printf("\n Rear=%d",p->rear);
	printf("\n Value deleted=%d",x);
}

void display(queue *p)
{
	int x;
	if(p->front==-1 && p->rear==-1)
	{
		printf("\n Underflow");
	}
	else
	{
		/*rear never crosses 4 to 0*/
		if(p->rear >= p->front)
		{
			for(x=p->front;x<=p->rear;x++)
			{
				printf("\t %d", p->a[x]);
			}
		}
		/* p->rear < p->front*/
		else
		{
			for(x=p->front;x<=max-1;x++)
			{
				printf("\t %d", p->a[x]);
			}
			for(x=0;x<=p->rear;x++)
			{
				printf("\t %d",p->a[x]);
			}
		}
	}
}

