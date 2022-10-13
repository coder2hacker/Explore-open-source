#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


// Function to print all binary numbers upto n

vector<string> generate(int N)
{
	// Your code here
	vector<string> v;
    queue<string> q;
    q.push("1");
    while(N--)
    {
        string curr=q.front();
        v.push_back(curr);
        q.pop();
        q.push(curr+"0");
        q.push(curr+"1");
    }
    return v;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
