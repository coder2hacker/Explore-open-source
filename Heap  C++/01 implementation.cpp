#include<iostream>
#include<vector>
using namespace std;

class minheap{
	vector<int>v; // internal representation of an heap
	void heapify(int i){
		int minIdx=i;
		int leftIdx=2*i+1; // left child
		if(leftIdx< v.size() && v[leftIdx]<v[minIdx]){
			minIdx=leftIdx;										
		}
		int rightIdx=2*i+2;
		if(rightIdx<v.size() && v[rightIdx]<v[minIdx]){
			minIdx=rightIdx;
		}                   
		if(minIdx != i){
			swap(v[i],v[minIdx]);
			heapify(minIdx);
		}           
	}
	public:
		void push(int data){
			v.push_back(data);
			int childIdx=v.size()-1; // i indx
			int parentIdx= childIdx%2==0 ? childIdx/2 - 1 : childIdx/2;

			while(parentIdx>=0 && v[parentIdx]>v[childIdx]){
				swap(v[parentIdx],v[childIdx]);
				childIdx=parentIdx; // check for upper tree
				parentIdx=childIdx%2==0 ? childIdx/2 - 1 : childIdx/2;
			}
		}
		void pop(){
			// we have to pop the minimum element which is at the root node
			// means at zero idx
			swap(v[0],v[v.size()-1]);
			v.pop_back();
			heapify(0);
		}
		bool empty(){
			return v.empty();
		}
		int top(){
			return v[0];
		}
};


int main(){
	minheap m;
	m.push(2);
	m.push(3);
	m.push(1);
	while(!m.empty()){
		cout<<m.top()<<" ";
		m.pop();
	}
	return 0;
}