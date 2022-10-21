#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void heapify(vector<int>&v, int n, int i){
	int maxIdx=i;
	int leftIdx=2*i+1;
	if(leftIdx<n && v[leftIdx]>v[maxIdx]){
		maxIdx=leftIdx;
	}
	int rightIdx=2*i+2;
	if(rightIdx<n && v[rightIdx]>v[maxIdx]){
		maxIdx=rightIdx;
	}
	if(maxIdx != i ){
		swap(v[maxIdx],v[i]);
		heapify(v,i,maxIdx);
	}
}

int main(){
	vector<int>v={1,4,2,5,6,3};
	int n=v.size();	
	// priority_queue<int>m;

	for(int i=n-1;i>=0;i--){
		heapify(v,n,i);
	}
	for(int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}

	return 0;
}