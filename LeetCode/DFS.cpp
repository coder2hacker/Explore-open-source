#define ll long long
bool isreachable(vector<int>&a, vector<int>&b) {
    ll x = (ll)(a[0] - b[0]) * (a[0] - b[0]);
    ll y = (ll)(a[1] - b[1]) * (a[1] - b[1]);
    ll r = a[2];
    return (x + y <= r * r);
}

void build_graph(vector<int>adj[], vector<vector<int>> &bombs, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                if (isreachable(bombs[i], bombs[j]))
                    adj[i].push_back(j);  //connect an edge from i to j
                //This graph may or may not be an undirected graph.
                //As bomb i can detonate bomb j then bomb j may or may not be able to
                //detonate bomb i.if it detonates then there will be a bi-directional edge.
            }
        }
    }
}

void dfs(int node, vector<int>adj[], vector<bool>&vis, int &det) {
    if (!vis[node]) {
        det++;
        vis[node] = true;
        for (auto i : adj[node])
            dfs(i, adj, vis, det);
    }
}

int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();
    int max_deto = 1;
    vector<int>adj[n];
    build_graph(adj, bombs, n);
    //perfrom dfs traversal from each node.
    for (int i = 0; i < n; ++i) {
        int detonations = 0;
        vector<bool>vis(n, false); //Inititalize this array everytime as from each node we have to traverse the path to know it's
        //number or detonations.
        if (!vis[i]) {
            dfs(i, adj, vis, detonations);
            max_deto = max(max_deto, detonations);
        }
    }
    return max_deto;
}

//TC - O(N2)
//SC - O(N2)

//DP won't work here as we can see there exists a visited array so dp won't be able to handle it.