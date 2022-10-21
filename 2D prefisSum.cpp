#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,m; cin>>n>>m;
    vector<vector<int>> a(n,vector<int> (m));


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cin>>a[i][j];
    }
	
	vector<vector<int>>prefix(n,vector<int>(m));
	 for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
        	prefix[i][j]=((i-1>=0?prefix[i-1][j]:0)+((j-1)>=0?prefix[i][j-1]:0)+a[i][j])- 
        				(i-1>=0 && j-1>=0?prefix[i-1][j-1]:0);
        }
    }
	
	for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cout<<prefix[i][j]<<" ";

        cout<<endl;
    }
	
	return 0;
}