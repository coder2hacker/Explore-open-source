#include <bits/stdc++.h>
using namespace std;

int CoinChangeWays(int coins[],int n,int W)
{
	int dp[n+1][W+1];
	//Base Conditions 
	for(int i=0;i<=n;i++)
	{
		dp[i][0]=1;
	}
	for(int j=1;j<=W;j++)
	{
		dp[0][j]=0;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=W;j++)
		{
			if(coins[i-1]<=j)
			{
				dp[i][j]= dp[i][j-coins[i-1]] + dp[i-1][j];
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

    int coins[] = {  1, 2, 3 };
    int n = sizeof(coins) / sizeof(coins[0]);
    int W=4; 
	int ans=CoinChangeWays(coins,n,W);
	cout<<ans<<"\n";
}
