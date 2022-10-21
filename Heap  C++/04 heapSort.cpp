#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int>&v ,int n, int i){ //max heap
	int maxidx=i;
	int leftidx=2*i +1;
	if(leftidx<n && v[leftidx]>v[maxidx]){
		maxidx=leftidx;
	}

	int rightidx=2*i +2;
	if(rightidx<n && v[rightidx]>v[maxidx]){
		maxidx=rightidx;
	}
	if(i != maxidx){
		swap(v[i],v[maxidx]);
		heapify(v,n,maxidx);
	}
}

int main(){
	vector<int> v = {1, 3, 2, 7, 5, 4, 6, 9, 8};
	int n = v.size();

	// build heap
	for(int i=n-1;i>=0;i--){
		heapify(v,n,i);
	}
	// heap sort
	int heapSize=n;
	while(heapSize>1){
		swap(v[0],v[heapSize-1]);  // swap the greater element with last
		heapSize--;			// now greater element is in correct posn so decrease heap size 
		heapify(v,heapSize,0); // call heapify to conver the heap to maxheap with less size
	}
	for(int i=0; i<n; i++) {
		cout << v[i] << " ";
	}
	
	return 0;
}
