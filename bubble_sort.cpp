#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[i])
			{
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
				
			}
		}
	}
		for(i=0;i<n;i++)
	cout<<a[i];
}
