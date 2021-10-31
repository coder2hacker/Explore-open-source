// 1. WAP to find factorial of a given number.

unsigned long long fact(int num){
    
    if(num == 0){
        return 1;
    }else{
        return num * fact(num -1);
    }
    
}

#include <stdio.h>
int main(){
    int num;
    printf("Enter number you want to find it's factorial : ");
    scanf("%d", &num);
    printf("%d! is %llu.", num , fact(num));
}