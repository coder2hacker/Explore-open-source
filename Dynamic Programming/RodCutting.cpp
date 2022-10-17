#include <bits/stdc++.h>
using namespace std;

int RodCutting(int price[],int len[],int n,int W)
{
	int dp[n+1][W+1];
	//Base Conditions 
	for(int i=0;i<=n;i++)
	{
		dp[i][0]=0;
	}
	for(int j=0;j<=W;j++)
	{
		dp[0][j]=0;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=W;j++)
		{
			if(len[i-1]<=j)
			{
				dp[i][j]= max(price[i-1]+dp[i][j-len[i-1]],dp[i-1][j]);
			}
			else
			{
				dp[i][j]= dp[i-1][j];
			}
		}
	}
	return dp[n][W];
}

int main()
{

    int price[] = {  1, 5, 8, 9, 10, 17, 17, 20 };
    int n = sizeof(price) / sizeof(price[0]);
    int len[n];
    for(int i=1;i<=n;i++)
    	len[i-1]=i;
	int ans=RodCutting(price,len,n,n);
	cout<<ans<<"\n";
}
