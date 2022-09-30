/* Insert keys into an array with double hashing technique of collision resolution technique. */
/* Data Structures Using C by UDIT AGARWAL */


#include<stdio.h>
#include<conio.h>
#define MAX 10
int a[MAX];
void dh(int , int[]);
void dhsr(int key, int a[MAX]);
void display(int a[MAX]);
void main()
{
int i, key,ch ;
for(i=0;i<MAX;i++)
	a[i] = '\0';
do{
	printf("\n\n Program for insertion/searching keys with double hashing ");
	printf("\n************************************************************\n\n");
	printf("\n 1. Insert keys ");
	printf("\n 2. Search key ");
	printf("\n 3. Display keys ");
	printf("\n 4. Exit ");
	printf("\n Select operation ");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1: do{
			printf("\n Enter key value [type -1 for termination] ");
			scanf("%d",&key);
			if (key != -1)

				dh(key,a);
			}while(key!=-1);
			break;
	case 2:	printf("\n Enter search key value ");
			scanf("%d",&key);
			dhsr(key,h);
			break;
	case 3: display(a);

		   break;
	}
	}while(ch!=4);
}

/* Find the location for a key and insert it */
void dh(int key, int a[MAX])
{
 int loc, i=0;
 loc = key % MAX;
 while (a[loc] !='\0')
	 loc = (loc + ++i*(key % (MAX -1))) % MAX;
 a[loc] = key;
 display(a);
} 

/* find the location for a key */
void dhsr(int key, int a[MAX])
{
 int loc,i=0;
 loc = key % MAX;
 while ((a[loc] != key) && (a[loc] !='\0'))
	 loc = (loc + ++i*(key % (MAX -1))) % MAX;
 if (a[loc] != '\0')
	printf("\n Search successful at index %d",loc);
 else
	printf("\n Search unsuccessful ");
} 

void display(int a[MAX])
{
int i;
printf("\n List of keys, 0 indicate that the location is empty \n");
for (i=0;i<MAX;i++)
	printf(" %d ",a[i]);
}