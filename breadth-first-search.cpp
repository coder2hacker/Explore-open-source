// C++ program implementing BFS (Breadth First Search)
// BFS is a traversal technique where level wise traversal take place where nodes in higher level are visited once all the nodes in lower levels are visited. 
// Queue data structure is used in this technique. 

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
vector<int> g[N];  // adjacency list 
int visited[N];

void bfs(int source){
    queue<int> q;
    q.push(source);
    visited[source] = 1;

    // From source vertex : 
    // 1. remove the firrst vertex of queue.
    // 2. mark the vertex as visited.
    // 3. Insert all unvisited nwighbours of vertex into queue.

    while (!q.empty()){
       int current_node = q.front();
       cout << current_node << " ";
       q.pop();
       for(int child: g[current_node]){
           if(!visited[child]){
               q.push(child);
               visited[child] = 1;
           }
       }
    }
    
}

int main(){
    
    int nodes, edges;
    cout << "Enter number of nodes and edges : ";
    cin >> nodes >> edges;

    cout << "Enter "<< edges << " pairs of src, dest vertices of a edge : ";
    for(int i=0; i< edges; i++){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    // assuming nodes start from 0 and assuming 0 as source vertex here
    cout << "Nodes are : " ;
    bfs(0);

    return 0;
}
