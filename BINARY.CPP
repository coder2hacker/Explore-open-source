/* Implementation of Binary Search */
/* Data Structures Using C by UDIT AGARWAL */

#include<stdio.h>
#include<conio.h>
void main()
{
char ch;
int arr[20],start,end,mid,n,i,data;
clrscr();
printf("\nHow many elements you want to enter in the array:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nEnter element %d:",i+1);
scanf("%d",&arr[i]);
}
printf("\n\nPress any key to continue...");
getch();
do
{
clrscr();
printf("\nEnter the element to be searched:");
scanf("%d",&data);
start=0;
end=n-1;
mid=(start + end)/2;
while(data!=arr[mid] && start <=end)
{
if(data > arr[mid])
start=mid+1;
else
end=mid-1;
mid=(start+end)/2;
}
if(data==arr[mid])
printf("\n%d found at position %d\n",data,mid + 1);
if(start>end)
printf("\n%d not found in array\n",data);
printf("\n\n Press <Y or y> to continue:");
fflush(stdin);
scanf("%c",&ch);
}while(ch == 'Y' || ch == 'y');
}