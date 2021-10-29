/*
WAP to print following patterns:
*
* *
* * *
* * * *
* * * * *

*
* *
* * *
* * * *
* * * * *

* * * * *
* * * *
* * *
* *
*

* * * * *
* * * *
* * *
* *
*

1
1 2
1 2 3
1 2 3 4
1 2 3 4 5

5 4 3 2 1
5 4 3 2
5 4 3
5 4
5

A
A B
A B C
A B C D
A B C D E

A B C D E
A B C D
A B C
A B
A

         *
       * * *
     * * * * *
  * *  * * * * *
* * *  * * * *  * 

*/

#include <stdio.h>
int main(){
    int gap = 8;

 printf(" Pattern 1 \n\n");

    for(int i = 0 ; i<= 4 ; ++i){
        for(int j = 0 ; j <= i ; ++j){
            printf("*");
        }

        printf("\n");
    }

 printf("\n Pattern 2 \n\n");

   for(int i = 4 ; i > 0 ; --i){
        for(int j = i ; j > 0 ; --j){
            printf("*");
        }

        printf("\n");
    }

printf("\n Pattern 3 \n");

    for(int i = 1 ; i<= 5 ; ++i){
        for(int j = 1 ; j <= i ; ++j){
            printf("%d", j);
        }

        printf("\n");
    }

printf("\n Pattern 4 \n\n");

    for(int i = 5 ; i > 0 ; --i){
        for(int j = i ; j > 0 ; --j){
            printf("%d",j);
        }

        printf("\n");
    }

printf("\n Pattern 5 \n\n");

    for(int i = 65 ; i<= 69 ; ++i){
        for(int j = 65 ; j <= i ; ++j){
            printf("%c", j);
        }

        printf("\n");
    }

printf("\n Pattern 6 \n\n");

    for(int i = 69; i > 64 ; --i){
        for(int j = i ; j > 64 ; --j){
            printf("%c",j);
        }

        printf("\n");
    }
printf("\n Pattern 7 \n\n");

    for(int i = 69; i > 64 ; --i){
        for(int j = i ; j > 64 ; --j){
            printf("%c",j);
        }

        printf("\n");
    }

printf(" Pattern 7 \n\n");

    for(int i = 0 ; i < 9 ; i+=2){
        for(int j = 0 ; j < gap ; j++){
            printf(" ");
        }
        for (int j = 0; j <= i  ; j++)
        {
           printf("*");
        }
        printf("\n");
        gap--;
    }



}