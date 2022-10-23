#include<stdio.h>
int s1=1,s2=0;
int fund(int n) // Tail recursion.
{  if(n>0)
   {
    printf("%d ",s1);
    s1=s1+s2;
    s2=s1-s2;
    fund(n-1);
    
   }
}

int funa(int n) //Head recursion.
{  if(n>0)
   {
    funa(n-1);
    printf("%d ",s1);
    s1=s1+s2;
    s2=s1-s2;
    
   }
}

int main()
{
    funa(5);
    fund(5);
    return 0;
}