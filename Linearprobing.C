/* Insert keys into an array with linear probing technique of collision resolution technique. */
/* Data Structures Using C by UDIT AGARWAL */

#include<stdio.h>
#include<conio.h>
#define MAX 10

int a[MAX];
void lp(int , int[]);
void lpsr(int key, int a[MAX]);
void display(int a[MAX]);

void main()
{
int i, key,ch ;
clrscr();
for(i=0;i<MAX;i++)
	a[i] = '\0';
  do{
	printf("\n\n Program for insertion/searching keys with linear probing ");
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
			    lp(key,a);
			}while(key!=-1);
			display(a);
			break;
	case 2:	printf("\n Enter search key value ");
			scanf("%d",&key);
			lpsr(key,a);
			break;
	case 3: display(a);
		break;
	}
	}while(ch!=4);
}

/* function lp find a location for key and insert it */
void lp(int key, int a[MAX])
{
 int loc;
 loc = key % MAX;
 while (a[loc] !='\0')
	 loc = ++loc % MAX;
 a[loc] = key;
}

/* function lpsr find a location for a key  */
void lpsr(int key, int a[MAX])
{
 int loc;
 loc = key % MAX;
 while ((a[loc] != key) && (a[loc] !='\0'))
	 loc=++loc%MAX;
 if (a[loc] != '\0')
	printf("\n Search successful at index %d",loc);
 else
	printf("\n Search unsuccessful ");
}

void display(int a[MAX])
{
int i;
printf("\n List of keys ('0' indicate that the location is empty): \n");
for (i=0;i<MAX;i++)
	printf(" %d ",a[i]);
}