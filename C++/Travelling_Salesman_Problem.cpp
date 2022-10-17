#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*
Travelling Salesman Problem...

A weighted Graph is Given, you have to traverse through each vertex exactly once and return to the
starting vertex such that the cost of travelling is least. (Also Known as Hamiltonian Cycle..)

Brute Force -->
Find the all premutation of the Paths and choose min cost path by iteratin them all 
T.C --> O(n!)

D.P -->  ( Top - Down )
Take 1 node as root node.

Traverse through the node and build rec tree(it will have 2^n vertices)...

From bottom of tree calculate the min cost req to reach par node...

int mask = bit-masking [1->0001(represent A is vis), 3->(0011)...] is used to keep track of visited nodes while building rec tree..

I have taken the max_constraint for 2d matrix but-->

DP size = [2^n][n]     [ row->keep track of visitness || col ->keep track of nodes ]

T.C --> O(n^2 * 2^n) ..

*/


/*

**********************************************************************************
|   Better Aprroach is to use map , instead of 2D matrix for memoization..      |
|   as u can see the output --> most of the dp entries in unutilized...         |
**********************************************************************************

*/


int dist[10001][10001] ; // Adjacency Matrix of Graph..

int dp[10001][10001] ;

int VISITED_ALL, n;

int TSP(int mask, int pos){
    if(mask==VISITED_ALL){
        return dist[pos][0]; // agar sabhi node visit kar liya to uss node se direct root node(i.e 1) tak ka cost add kr k return...
    }

    if(dp[mask][pos]!=-1){
        return dp[mask][pos];
    }

    int ans = INT_MAX;

    F(0,n,city){
        if((mask&(1<<city))==0){             //[chcking no city is visited more than once, as 1&1=1 always]
            int newAns = dist[pos][city] + TSP( mask|(1<<city), city);  // or operation is used to mark the visted city ..
            ans = min(ans,newAns);
        }

    }

    return dp[mask][pos] = ans;

}


int32_t main()
{
    cin>>n;

    memset(dp, -1, sizeof(dp));

    F(0,n,i){
        F(0,n,j){
            cin>>dist[i][j];
        }
    }

    VISITED_ALL = (1<<n) - 1;

    cout<<TSP(1,0)<<" "<<dp[1][0]<<"\n";

    F(0,16,i){
        F(0,4,j){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }

}

/*
gfg e.g->
4
0 10 15 20
10 0 25 25
15 25 0 30
20 25 30 0
4
0 20 42 25
20 0 30 34
42 30 0 10
25 34 10 0

*/
