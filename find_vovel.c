// 10. Write a C program to find out given character is vowel or not.

# include <stdio.h>
int main(){
    char ch;
    int small_vovel, big_vovel;
    printf("Enter a charecter you want to check ");
    scanf("%c" , &ch);
    small_vovel = ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    big_vovel = ( ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    if( small_vovel || big_vovel){
        printf(" Your Entered charecter %c is Vovel" , ch);
    }else{
        printf(" Your Entered charecter %c is Consonent" , ch);
    }
    
}