//Topological sort using DFS

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int>v;
	void DFStoposort(int s,vector<int>&visited,stack<int>&st,vector<int> adj[])
	{
	    visited[s]=1;
	    for(auto x:adj[s])
	    {
	        if(visited[x]==0)
	            DFStoposort(x,visited,st,adj);
	    }
	    st.push(s);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    v.clear();
	   // st.clear();
	    vector<int> visited(V,0);
	    stack<int>st;
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==0)
	            DFStoposort(i,visited,st,adj);
	    }
	    
	    while(!st.empty())
	    {
	        int val=st.top();
	        v.push_back(val);
	        st.pop();
	    }
	    return v;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends
