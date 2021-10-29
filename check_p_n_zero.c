// 18. WAP to check whether a number is positive, negative or zero using switch statement.

#include <stdio.h>
int main(){
    int num;
    printf("Please enter numbers :");
    scanf("%d", &num);
    
    switch (num > 0)
    {
    case 1:
        printf(" You entered %d, Which is Postive.", num);
        break;
    case 0:
        switch (num < 0)
        {
        case 1:
            printf(" You entered %d, Which is Negative.", num);
            break;
        case 0:
            printf("You entered Zero.");
            break;
        default:
           printf("Please enter vaild digit ");
           break;
        }
    
    }  
    
}