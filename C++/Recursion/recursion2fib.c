#include<stdio.h>
void fib(int n)
{ 
    int s1=1,s2=0;
    for(int i=1;i<=n;i++)
    {  
        printf("%d ",s1);
        s1=s1+s2;
        s2=s1-s2;   
    }
}

int s1=1,s2=0;
int fibr(int n) // Tail recursion.
{  if(n>0)
   {
    printf("%d ",s1);
    s1=s1+s2;
    s2=s1-s2;
    fibr(n-1);
    
   }
}
int main()
{   fib(10);
    return 0;
}