
//Using Recursion && Memoization

//Time Complexity :- O(N * N)

//Space Complexity :- O(N * N)

// DP 


class Solution {
public:
    
    int dp[2005];
    
    vector<vector<bool>> is_palin;
    
    // fill palin
    
    void fill_palin(string str)
    {
        int n = str.size();
        
        for(int gap = 0; gap < n; gap++)
        {
            for(int i = 0; i + gap < n; i++)
            {
                int j = i + gap;
                
                if(gap == 0)
                {
                    is_palin[i][j] = true;
                }
                else if(gap == 1)
                {
                    is_palin[i][j] = (str[i] == str[j]);
                }
                else
                {
                    if(str[i] == str[j])
                    {
                        is_palin[i][j] = is_palin[i + 1][j - 1];
                    }
                }
            }
        }
    }
    
    int helper(string& str, int i, int n)
    {
        // base case
        
        if(i == n)
            return 0;
        
        // if already calculated
        
        if(dp[i] != -1)
        {
            return dp[i];
        }
        
        // cut the string where we are getting palindrome and call for next
        
        int mini = INT_MAX;
        
        for(int j = i; j < n; j++)
        {
            if(is_palin[i][j])
            {
                mini = min(mini, 1 + helper(str, j + 1, n));
            }
        }
        
        // store the res and return it
        
        return dp[i] = mini;
    }
    
    int minCut(string str)
    {
        
        int n = str.size();
        
        // is_palin will store that substring between [i, j] is palindrome or not
        
        // so that we do not have to run palindrome checking function every time
        
        // this will help in reducing time complexity, now we will always check in O(1)
        
        is_palin.resize(n);
        
        is_palin.assign(n, vector<bool> (n, false));
        
        // fill palin 
        
        fill_palin(str);
        
        // declare a dp with -1
        
        memset(dp, -1, sizeof(dp));
        
        return helper(str, 0, n) - 1;
    }
};
