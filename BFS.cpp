#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adjList,int source,int N){
	vector<bool> visited(N,false);
	
	queue<int> q;
	visited[source]=true;
	q.push(source);
	
	while(!q.empty()){
		int currentNode=q.front();
		cout<<"Visited: "<<currentNode<<endl;
		q.pop();
		int totalNeighbour = adjList[currentNode].size();
		
		for(int i=0;i<totalNeighbour;i++){
			int neighbourNode = adjList[currentNode][i];
			
			if(visited[neighbourNode]==false){
				visited[neighbourNode]=true;
				q.push(neighbourNode);
			}
		}
	}
}

int main(){
	
	int N=6;
	
	vector<vector<int>> adjList(N);
	
	adjList[0].push_back(1);
	adjList[0].push_back(2);
	adjList[0].push_back(4);
	
	adjList[1].push_back(3);
	adjList[2].push_back(3);
	adjList[3].push_back(4);
	adjList[3].push_back(5);
	
	bfs(adjList,0,N);
	
}
