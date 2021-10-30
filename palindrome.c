// 3. WAP to check a given number is palindrome or not. ex 121, 1551
// ( If reverse of a number and number is same, then it is called palindrome).

void palindrome(int num){
    int reverse = 0;
    int original = num;
    while (num != 0)
    {
        reverse = reverse * 10 + num % 10 ;
        num /= 10;
    }
    if(original == reverse){
        printf(" %d number is palindrome" , original);
    }else{
         printf(" %d number is NOT palindrome" , original);
    }
    
}

#include <stdio.h>
int main(){
    int num;
    printf("Enter number you want to check palindrome or not : ");
    scanf("%d", &num);
    palindrome(num);
}