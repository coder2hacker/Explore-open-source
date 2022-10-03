#include<stdio.h>
#include<string.h>
int main()
{
	char a[30],t;
	int i,j;
	printf("enter a string");
	gets(a);
	puts(a);
	for(i=0;a[i]!='\0';i++)
	{
		for(j=i+1;a[j]!='\0';j++)
		{
			if(a[i]<a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	printf("%s",a[i]);
	return 0;
}
