// 16. WAP to print reverse of a 4 digit number.

#include <stdio.h>

int reverse(int num){
    int reverseNum = 0 ;  

    while(num > 0 ){
        reverseNum = reverseNum * 10 + num % 10;
        num = num / 10 ;
    }
    return reverseNum;
}
          
int main()
{
    int num ;
    printf("Enter 4 digit number : ");
    scanf("%d", &num);
    printf("Reverse of %d is %d", num, reverse(num));
    return 0;
}


