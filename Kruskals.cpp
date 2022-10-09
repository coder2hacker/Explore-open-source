//C++ program to implement the Kruskal's algorithm to find the minimum spanning tree in an undirected graph
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//C++ structure to implement Disjoint Set Union Data Structure
//DSU is used to efficiently query if a particular edge forms a cycle in O(alpha(n)) using path compression
//where alpha is the inverse Ackermann function
struct DSU{
    vector<int> parent;
    vector<int> size;
    int comps;//number of components in the graph 
        
    DSU(int N){
        parent = vector<int>(N);
        size = vector<int>(N, 1);
        comps = N;
        for(int i=0; i<N; i++){
            parent[i] = i;
        }
    }

    //find operation using path compression    
    int find(int i){
        while(i != parent[i]){
            parent[i] = parent[parent[i]]; // compress
            i = parent[i];
        }
        return i;
    }
        
    bool Union(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return false;//union cant be done since results in cycle
        
        comps--;
        if(size[a] < size[b]){
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
        return true;//union can be done since doesnt result in a cycle
    }
};

// Comparator function used for sorting edges based on their weight
struct comp{
	bool operator () (vector<int>& a, vector<int>& b) const{
		return a[2]<b[2];
	}
};

int main(){
	int v, e;
    cout<<"Enter the number of vertices and edges in the graph respectively: "<<endl;
	cin>>v>>e;
	int src, dest, wt;
	vector<vector<int>> edges(e, vector<int>(3));
    cout<<"For each edge enter the corresponding pair of vertices(in 1 base indexing) and the edge weight respectively: "<<endl;
	for(int i=0; i<e; i++){
		cin>>src>>dest>>wt;
		src--;
		dest--;
		edges[i] = {src, dest, wt};
	}

    // Sort all the edges in ascending order of their weight
    // O(ElogE)
	sort(edges.begin(), edges.end(), comp());
 
	DSU dsu(v);
 
    // Index used to pick next edge
	int i=0;
    // An index variable, used for mst[]
    int included=0;
	long long mincost=0;
	vector<int> edge;
    vector<vector<int>> mst(v-1, vector<int>(3));

    // Number of edges to be taken is equal to V-1
    // O(V*alpha(V)) = O(V)
	while(included<v-1){
		edge = edges[i++];
		src = edge[0];
		dest = edge[1];
		wt = edge[2];
        //O(alpha(V)) ~= O(1)
		if(!dsu.Union(src, dest)) continue;
        // If including this edge doesn't cause cycle, include it in result and increment the index
        // of result for next edge
		mincost += wt;
		mst[included++] = edge;
	}
    cout<<"Following are the edges in the constructed MST: "<<"\n";
    for (i = 0; i < included; ++i) {
        cout<<mst[i][0]<<"--"<<mst[i][1]<<" == "<<mst[i][2]<<"\n";
    }
	cout<<"Minimum Cost: "<<mincost;
    // INPUT:
    // 4 5
    // 1 2 7
    // 1 4 6
    // 4 2 9
    // 4 3 8
    // 2 3 6
    
    // OUTPUT:
    // Following are the edges in the constructed MST: 
    // 0--3 == 6
    // 1--2 == 6
    // 0--1 == 7
    // Minimum Cost: 19

    //Time Complexity: ElogE for sorting edges + V ~= O(ElogE)
    //Space Complexity: Auxilliary space O(V) for DSU
}