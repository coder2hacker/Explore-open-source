//Incomplete Solution

#include <bits/stdc++.h>
using namespace std;

int MinimumCoinChange(int coins[],int n,int W)
{
	int dp[n+1][W+1];
	//Base Conditions 
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=0;
	}
	for(int j=0;j<=W;j++)
	{
		dp[0][j]=INT_MAX-1;
	}
	
	for(int j=0;j<=W;j++)
	{
		if(j%coins[0]==0)
			dp[1][j]=j/coins[0];
		else
			dp[1][j]=INT_MAX-1;
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=W;j++)
		{
			if(coins[i-1]<=j)
			{
				dp[i][j]= min(1+dp[i][j-coins[i-1]] , dp[i-1][j]);
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
	int ans=MinimumCoinChange(coins,n,W);
	cout<<ans<<"\n";
}
