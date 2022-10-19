//Program by Swaraj Shelavale @errorless111

#include <bits/stdc++.h>
#include <fstream>
using namespace std;

long long findNthFibonacci(int number);

 // } Driver Code Ends


//User function Template for C++
// You need to complete this function

// Return the number-th Fibonacci 
static long dp[100];
long long findNthFibonacci(int number)
{
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=number;i++)
        dp[i]=dp[i-1]+dp[i-2];
    return dp[number];
    
}

// { Driver Code Starts.

int main()
 {
    //taking testcases
    int testcases;
    cin>>testcases;
    
    while(testcases--)
    {
        //taking nth fibonacci 
        //to be found
        int number;
        cin>>number;
        
        //calling function findNthFibonacci()
        //and passing number as parameter
        cout<<findNthFibonacci(number)<<endl;
    }
    
	return 0;
}
  // } Driver Code Ends
