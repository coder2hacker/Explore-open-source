// Linear search Algorithm implementation using C//
#include<stdio.h>
int main()
{
	int array[100];
	int i,num,keynum,found=0;
	printf("Enter the range of the elements:\n");
	scanf("%d",&num);
	printf("Enter the elements:\n");
	for(i=0;i<num;i++)
	{
		scanf("%d",&array[i]);
	}
	printf("Input array is\n");
	for(i=0;i<num;i++)
	{
		printf("%d\n",array[i]);
	}
	printf("Enter the element to be searched\n");
	scanf("%d",&keynum);
	
	// Linear search begins//
	
	for(i=0;i<num;i++)
	{
		if(keynum==array[i])
		{
			found=1;
			break;
		}
	}
	if(found==1)
		printf("Element is present in the array\n");
		
	else
		printf("Element is not found in the array\n");
return 0;
}
