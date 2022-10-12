#include <bits/stdc++.h>
using namespace std;

int subsetSum(int arr[],int n,int sum)
{
	int dp[n+1][sum+1];
	//Base Conditions 
	for(int i=0;i<=n;i++) //sum=0
	{
		dp[i][0]=1;
	}
	for(int j=1;j<=sum;j++) //array size in zero
	{
		dp[0][j]=0;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(arr[i-1]<=j)
			{
				dp[i][j]= dp[i-1][j-arr[i-1]] + dp[i-1][j];
			}
			else
			{
				dp[i][j]= dp[i-1][j];
			}
		}
	}

	return dp[n][sum];
}

int main()
{

    int arr[] = {1,1,1,1,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int diff=3,sum=0;
	sum=accumulate(arr,arr+n,sum);
	int s1=(diff+sum)/2;
	int ans=subsetSum(arr,n,s1);
	cout<<ans<<"\n";
}
