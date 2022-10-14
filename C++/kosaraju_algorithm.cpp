	//Function to find number of strongly connected components in the graph.

    // Time complexity O(V+E)
    
	int vis[5001];
	int vis2[5001];
	void topo(int v,vector<int>adj[],stack<int>&s)
	{
	    vis[v]=1;
	    for(auto it:adj[v])
	    {
	        if(!vis[it])
	        {
	            topo(it,adj,s);
	        }
	    }
	    s.push(v);
	}
	void dfs(int v,vector<int>adj[])
	{
	    vis2[v]=1;
	    for(auto it:adj[v])
	    {
	        if(!vis2[it])
	        {
	            dfs(it,adj);
	        }
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        memset(vis,0,sizeof(vis));
        stack<int>s;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                topo(i,adj,s);
            }
        }
        vector<int>adjT[V];
        for(int i=0;i<V;i++)
        {
            if(adj[i].size()>0)
            {
                for(auto it:adj[i])
                {
                    adjT[it].push_back(i);
                }
            }
        }
        memset(vis2,0,sizeof(vis2));
        int ans=0;
        while(!s.empty())
        {
            int v=s.top();
            s.pop();
            if(!vis2[v])
            {
                ans++;
                dfs(v,adjT);
            }
        }
     
        return ans;
    }