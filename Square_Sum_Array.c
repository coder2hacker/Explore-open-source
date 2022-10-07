/* Take input the elements of an array. find the sum of their squares. */
#include<stdio.h>
int main()
{
    int arr[5],sum=0,val;
    // Take inputs of an array
    printf("Enter Elements: ");
    for(int i=0;i<5;i++)
        scanf("%d",&arr[i]);
    
    // Calculation
    for(int i=0;i<5;i++)
    {
        sum=sum+(arr[i]*arr[i]);
    }

    //Printing Result
    printf("Values\t\tSquare Values");
    printf("\n");
    for(int i=0;i<5;i++)
    {
        printf("%d\t\t" "%d",arr[i],arr[i]*arr[i]);
        printf("\n");
    }
    printf("The Sum is: %d",sum);

    return 0;
}