//Detect Cycle in Diaercted Graph

class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	vector<int>v;
    bool dfs(int s,vector<int> &visited,vector<int> &order,vector<int>adj[])
	{
	    visited[s]=1;
	    order[s]=1;
	    for(auto x:adj[s])
	    {
	        if(visited[x]==0)
	        {
	            bool ans2=dfs(x,visited,order,adj);
	            if(ans2)
	                return true;
	        }
	        else if(order[x])
	            return true;
	    }
	    order[s]=0;
	    return false;
	}
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	vector<int>visited(V,0),ord(V,0);
	   	for(int i=0;i<V;i++)
	   	{
	   	    if(visited[i]==0)
	   	    {
	   	        bool ans=dfs(i,visited,ord,adj);
	   	        if(ans)
	   	            return true;
	   	    }
	   	}
	   	return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
