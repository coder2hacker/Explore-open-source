/* Program of Dqueue*/
/* Data Structures Using C by UDIT AGARWAL */
#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#define MAX 10
void addqatbeg ( int *, int, int *, int * ) ;
void addqatend ( int *, int, int *, int * ) ;
int delqatbeg ( int *, int *, int * ) ;
int delqatend ( int *, int *, int * ) ;
void display ( int * ) ;
int count ( int * ) ;
void disp();
void main( )
{
int arr[MAX] ;
int front, rear, i, n ;
clrscr() ;
/* initialize data members */
front = rear = -1 ;
for ( i=0;i<MAX;i++ )
arr[i] = 0;

int ch, data;
disp();
while (1)
{
printf("\n Enter the Choice");
scanf("%d", &ch);
switch(ch)
{
case 0: 
disp();
break;
case 1:
printf("\n Enter the Element");
scanf("%d", &data);
addqatbeg ( arr, data, &front, &rear ) ;
break;
case 2:
printf("\n Enter the element");
scanf("%d", &data);
addqatend ( arr, data, &front, &rear ) ;
break;
case 3:
i = delqatbeg ( arr, &front, &rear ) ;
printf ( "\nItem extracted: %d", i ) ;
break;
case 4: 
i = delqatend ( arr, &front, &rear ) ;
printf ( "\nItem extracted: %d", i ) ;
break;
case 5:
n = count ( arr);
printf("Number of elements in dequeue is %d",n);
break;
case 6: 
display(arr);
break;
case 7:
exit(0);
default:
printf("Please enter right choice....");
}
}
getch();
}
void disp( )
{
printf("\nRepresentation of Dequeue");
printf("\n\**************************\n");
printf("\n\t 1.Enqueue at front");
printf("\n\t 2.Enqueue at rear");
printf("\n\t 3.Dequeue at front");
printf("\n\t 4.Dequeue at rear");
printf("\n\t 5.Size of the queue");
printf("\n\t 6.view");
printf("\n\t 7.Exit");
}
/* adds an element at the beginning of a deque */
void addqatbeg ( int *arr, int item, int *pfront, int *prear )
{
int i, k, c ;
if ( *pfront == 0 && *prear == MAX - 1 )
{
printf ( "\nDeque is full.\n" ) ;
return ;
}
if ( *pfront == -1 )
{
*pfront = *prear = 0 ;
arr[*pfront] = item ;
return ;
}
if ( *prear != MAX - 1 )
{
c = count ( arr ) ;
k = *prear + 1 ;
for ( i = 1 ; i <= c ; i++ )
{
arr[k] = arr[k - 1] ;
k-- ;
}
arr[k] = item ;
*pfront = k ;
( *prear )++ ;
}
else
{
( *pfront )-- ;
arr[*pfront] = item ;
}
}
/* adds an element at the end of a deque */
void addqatend ( int *arr, int item, int *pfront, int *prear )
{
int i, k ;
if ( *pfront == 0 && *prear == MAX - 1 )
{
printf ( "\nDeque is full.\n" ) ;
return ;
}
if ( *pfront == -1 )
{
*prear = *pfront = 0 ;
arr[*prear] = item ;
return ;
}
if ( *prear == MAX - 1 )
{
k = *pfront - 1 ;
for ( i = *pfront - 1 ; i < *prear ; i++ )
{
k = i ;
if ( k == MAX - 1 )
arr[k] = 0 ;
else
arr[k] = arr[i + 1] ;
}
(*prear)-- ;
(*pfront)-- ;
}
(*prear)++ ;
arr[*prear] = item ;
}

/* removes an element from the *pfront end of deque */
int delqatbeg ( int *arr, int *pfront, int *prear )
{
int item ;
if ( *pfront == -1 )
{
printf ( "\nDeque is empty.\n" ) ;
return 0 ;
}
item = arr[*pfront] ;
arr[*pfront] = 0 ;
if ( *pfront == *prear )
*pfront = *prear = -1 ;
else
( *pfront )++ ;
return item ;
}

/* removes an element from the *prear end of the deque */
int delqatend ( int *arr, int *pfront, int *prear )
{
int item ;
if ( *pfront == -1 )
{
printf ( "\nDeque is empty.\n" ) ;
return 0 ;
}
item = arr[*prear] ;
arr[*prear] = 0 ;
( *prear )-- ;
if ( *prear == -1 )
*pfront = -1 ;
return item ;
}
/* displays elements of a deque */
void display ( int *arr )
{
int i ;
printf ( "\n front->" ) ;
for ( i = 0 ; i < MAX ; i++ )
printf ( "\t%d", arr[i] ) ;
printf ( " <-rear" ) ;
}
/* counts the total number of elements in deque */
int count ( int *arr )
{
int c = 0, i ;
for ( i = 0 ; i < MAX ; i++ )
{
if ( arr[i] != 0 )
c++ ;
}
return c ;
}