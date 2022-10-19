#include <bits/stdc++.h>
using namespace std;

bool SequencePatternMatching(int n,int m,string a,string b)
{
	int dp[n+1][m+1];
	//Base Conditions 
	for(int i=0;i<=n;i++)
	{
		dp[i][0]=0;
	}
	for(int j=0;j<=m;j++)
	{
		dp[0][j]=0;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i-1]==b[j-1])
			{
				dp[i][j]= 1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	return dp[n][m]==n;
	
}

int main()
{
	string a = "abc";
    string b = "adbac";
	bool ans=SequencePatternMatching(a.size(),b.size(),a,b);
	cout<<ans<<"\n";
	return 0;
}
