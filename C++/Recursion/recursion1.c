#include<stdio.h>

void func(int n)
{
    if(n>0)
    {   
        func(n-1);
        printf("%d ",n);
    }
}

int sum(int n)
{
    if(n>0)
    return sum(n-1)+n;
    else
    return 0;

}
int main()
{    
//     int x=3;
//     func(x);
      printf("%d",sum(5));

    return 0;
}