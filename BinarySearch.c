#include<stdio.h>
#include<stdlib.h>
int bs(int *,int ,int ,int );
int main()
{
 int *p,i,f,n,c,s=0,e;
 printf("ENTER THE NUMBER OF ELEMENTS WANT TO INPUT : ");
 scanf("%d",&n);
 p=(int *)malloc(n*sizeof(int));
 printf("\n\nENTER THE ELEMENTS IN ASCENDING ORDER \n\n");
 for(i=0;i<n;i++)
 {
 scanf("%d",(p+i));
 }
 e=n-1;
 printf("ENTER THE ELEMENT WANT TO SEARCH : ");
 scanf("%d",&f);
 c=bs(p,s,e,f);
 if(c==-1)
 {
 printf("THE ELEMENT IS NOT FOUND");
 }
 else
 {
 printf("THE ELEMENT %d IS FOUND AT POSITION %d\n",f,c);
 }
 return 0;
}

int bs(int *a,int start,int end,int search)
{
 int mid;
 mid=(start+end)/2;
 if(start>end)
 {
 return -1;
 }
 if(*(a+mid)==search)
 {
 return mid+1;
 }
 if(search<*(a+mid))
 {
 end=mid-1;
 bs(a,start,end,search);
 }
 else if(search>*(a+mid))
 {
 start=mid+1;
 bs(a,start,end,search);
 }
}