#include<stdio.h>
int f=1;
int fact(int n)
{   if(n>0)
    {  f=f*n;
       fact(n-1);
    }
    return f;
}
int factr(int n)
{   if(n>0)
    {
       return fact(n-1)*n;
    }
    else
    return 1; 
}

int Pow (int num, int n)
{static int res=1;
 if(n>0)
    {  
       res=res*num;
       Pow(num,n-1);
    }
    return res;
}

int Powr (int num, int n)
{
 if(n>0)
    {        
       return Pow(num,n-1)*num;
    }
    else 
    return 1;
}
int main()
{ //int x=Powr(5,3);
 //printf("%d",fact(4));
 printf("%d",Powr(5,3));
return 0;
}