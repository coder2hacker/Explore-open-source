/* Program to multiply two natural numbers.*/
/* Data Structures Using C by UDIT AGARWAL */
#include<stdio.h>
#include<conio.h>
int evalmul (int i, int j)
{
if(i == 0, j == 0)
{
return 0;
}
if(j == 1)
{
return i;
}
return (evalmul (i, j-1) + i);
}
void main()
{
clrscr();
int i,j,result;
printf("Enter the two elements :\n");
scanf("%d %d", &i, &j);
result = evalmul(i, j);
printf("The multiplication of (%d, %d)=%d", i, j, result);
getch();
}
