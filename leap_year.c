// 11. Write a C program to find out given year is leap year or not.

#include <stdio.h>
int main(){
    int year;
    printf("Enter the Year you want to find that is leap year \n");
    scanf("%d", &year);
    if(year % 4 == 0){
        printf("%d is Leap year", year);
    }else{
        printf("%d is not a leap year", year);
    }
}