//21. WAP to display the size of all primary data type

#include <stdio.h>
int main()
{
    char char_var = 'a';
    int int_var = 1;
    float float_var = 1.0;
    double double_var = 1.0000000;

    printf("Size of Charecter variable %c is %d byte \n" , char_var , sizeof(char_var));
    printf("Size of Integer variable %d is %d bytes \n", int_var , sizeof(int_var));
    printf("Size of Float variable %f is %d bytes \n" , float_var , sizeof(float_var));
    printf("Size of Doble variable %lf is %d bytes \n" , double_var , sizeof(double_var));
}


