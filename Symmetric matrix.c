#include<stdio.h>
int main()
{
	int m,n,c,d,a[10][10],b[10][10],count=1;
	printf("enter the number of rows and columns:\n");
	scanf("%d%d",&m,&n);
	printf("enter the matrix elements\n");
	for(c=0;c<m;c++)
	{
		for(d=0;d<n;d++)
		{
			scanf("%d",&a[c][d]);
		}
	}
	for(c=0;c<m;c++)
	{
		for(d=0;d<n;d++)
		{
			b[d][c]=a[c][d];
		}
	}
	for(c=0;c<m;c++)
	{
		for(d=0;d<n;d++)
		{
			if(a[c][d]!=b[c][d])
			{
				count++;
				break;
			}
		}
	}
	if(count==1)
	{
		printf("symmetric matrix");
	}
	else
	{
		printf("not a symmetric matrix");
	}
	return 0;
}
