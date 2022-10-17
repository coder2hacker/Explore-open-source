#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*
N stones are there(1 to n) a frog is initally is at stone 1, he can jump to the next or
second next stone at a time, every jump costs ( |Hj - Hi| while jumping from i to j) -- (h1,h2...hN will be given)..
find the minimum cost to reach n...
*/

// TC = O(N);

int32_t main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vi H(n);
        F(0,n,i){cin>>H[i];} // 1 indexed

        int dp[n+1];
        dp[0] = 0;                    // initialization as it will cost 0 to be on 1st stone
        dp[1] = abs(H[1] - H[0]);     // initialization as there is only onw way to go on 2nd step

        F(2,n,i){
            int x = dp[i-1]+abs(H[i]-H[i-1]);
            int y = dp[i-2]+abs(H[i]-H[i-2]);
            dp[i] = min(x,y);
        }

        cout<<dp[n-1]<<"\n";
    }

}
