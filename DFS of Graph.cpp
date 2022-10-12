// DFS of graph

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
    vector<int> v;
	void dfs(int s,vector<int>&visited,vector<int> adj[])
	{
	    visited[s]=1;
	    v.push_back(s);
	    
	    for(auto x:adj[s])
	        if(visited[x]==0)
	            dfs(x,visited,adj);
	    
	}
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    v.clear();
	    vector<int> visited(V,0);
	    dfs(0,visited,adj);
	   return v;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
