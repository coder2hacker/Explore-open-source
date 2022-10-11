#include<stdio.h>
int main()
{
    int temp,a[100],b[100],c[200],i,j,k=0,n,limit;
    printf("Enter the limit of arrays: ");
    scanf("%d", &n);
    printf("Enter the elements of array a: ");
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the elements of array b: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }   
    limit=2*n ;
    for(i=0;i<limit;i++){
        c[i]=a[i];
        if(i>n-1){
            c[i]=b[i-n];
        }
    }
    for(i=0;i<limit-1;i++){
        for(j=i+1;j<limit;j++){
            if(c[i]> c[j]){
                temp=c[i];
                c[i]=c[j];
                c[j]=temp;
            }
        }
    }
    printf("The sorted array is: ");
    for(i=0;i<limit;i++){
        printf("%d ",c[i]);
    }

    return 0;
}