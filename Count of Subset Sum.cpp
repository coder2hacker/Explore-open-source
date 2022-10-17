#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define fast                    \
    cin.sync_with_stdio(false); \
    cin.tie(NULL);              \
    cout.tie(NULL);

int dp[1001][10001];
int CountOfSubsetSum(int n, int arr[], int sum)
{
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
signed main()
{
    fast;
    int n = 4;
    int arr[4] = {1, 2, 3, 3};
    int sum = 6;
    //memonization
    memset(dp, -1, sizeof(dp));

    cout << CountOfSubsetSum(n, arr, sum);

    return 0;
}
