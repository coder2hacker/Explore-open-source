#include<stdio.h>
#include<conio.h>

void main(){

int one, two, sub;

printf("Enter first number - ");

scanf("%d",&one);

printf("Enter second number - ");

scanf("%d",&two);

sub = one - two;

printf("The subtraction of numbers %d and %d is %d",one,two,sub);

getch();

}


int main() {    

    int number1, number2, sum;
    
    printf("Enter two integers: ");
    scanf("%d %d", &number1, &number2);

    // calculating sum
    sum = number1 + number2;      
    
    printf("%d + %d = %d", number1, number2, sum);
    return 0;
}


//End of the program.
