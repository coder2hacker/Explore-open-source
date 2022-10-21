/*  The cost to connect two ropes is equal to the sum of their lengths. We need to connect the 
    ropes with minimum cost.   */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
	vector<int> ropeLengths = {4, 3, 2, 6};
	// priority_queue<int, vector<int>, greater<int>> minHeap;
    // for(int i=0; i<ropeLengths.size(); i++) {
    //     minHeap.push(ropeLengths[i]);
    // }
	priority_queue<int,vector<int>,greater<int>>minHeap(ropeLengths.begin(),ropeLengths.end());
	int total=0;
	while(minHeap.size()>1){  // when we push last sum in heap then there will be no other rope left to merge
		int a=minHeap.top(); minHeap.pop();
		int b=minHeap.top(); minHeap.pop();
		total+=(a+b);
		minHeap.push((a+b));
	}
	cout<<total;
	return 0;
}