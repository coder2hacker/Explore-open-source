#include<stdio.h>
#include<string.h>
int main()
{
	char a[30];
	int i;
	printf("enter a string");
	gets(a);
	puts(a);
	for(i=0;a[i]!='\0';i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
	return 0;
}
