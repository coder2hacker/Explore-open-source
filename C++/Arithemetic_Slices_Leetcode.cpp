#include<bits/stdc++.h>
using namespace std;
#define ll long long

int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    if (n <= 2)
        return 0;
    vector<unordered_map<pair<ll, int>, int>>dp(n);
    int ans = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = i - 1; j >= 0; j--) {
            ll cd = (ll)nums[i] - nums[j];
            dp[i][ {cd, -1}] += dp[j][ {cd, -1}] + dp[j][ {cd, 2}];
            dp[i][ {cd, 2}] += 1;

            ans += dp[j][ {cd, -1}] + dp[j][ {cd, 2}];
        }
    }

    return ans;
}