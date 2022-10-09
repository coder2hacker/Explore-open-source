// Binary search algorithm implementation using C //

#include<stdio.h>
int main()
{
	int c,first,last,middle,n,search,array[100];
	printf("Enter the range of the elements:\n");
	scanf("%d",&n);
	printf("Enter %d integers:\n",n);
	for(c=0;c<n;c++)
		scanf("%d",&array[c]);
	printf("Enter the value to find:\n");
	scanf("%d",&search);
	first=0;
	last=n-1;
	middle=(first+last)/2;
	while(first<=last)
	{
		if(array[middle] == search)
		{
			printf("%d is found in the location %d\n",search,middle+1);
			break;
		}
		else if(array[middle] < search)
			first=middle+1;
		else
			last=middle-1;
		middle=(first+last)/2;
	}
	if(first > last)
		printf("Not Found!! %d is not present in the list/n",search);
return 0;	
} 
