// 14. WAP to check whether an input character is an alphabet, digit or special character

#include <stdio.h>
int main(){
    char ch;
    printf("Enter a charecter you want to check : ");
    scanf("%c" , &ch);
    if( 33 <= ch &&  ch < 48){
       printf(" Your are enterterd a special character ");
    }else if( 48 <= ch &&  ch < 58){
        printf(" Your are enterterd a digit ");
    }else if( 65 <= ch &&  ch < 91 || 97 <= ch &&  ch < 123){
        printf(" Your are enterterd an Alphabet ");
    }else{
        printf(" Please enter an alphabet, digit or special character ");
    }
    
}