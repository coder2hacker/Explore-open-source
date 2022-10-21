/* Given an infinite stream of non-negative integers, design an algorithm to output the 
top-K integers every time you encounter -1.
Example : Input = 4, 1, 2, -1, 3, -1 7 0 1 2 -1 8 -1 . . . ; K = 3
          Output = 1 2 4
                   2 3 4
                   3 4 7
                   4 7 8 */
#include<iostream>
#include<queue>
#define pq_min priority_queue<int, vector<int>, greater<int>>

using namespace std;
void printHeap(pq_min minHeap) {
    while(!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}
int main(){
	pq_min minHeap;
	int data;
	int k=3,i=0;
	while(i<k){
		cin >> data;
        minHeap.push(data);
        i++;
	}
	while(true){
		cin>>data;
		if(data == 0){
			// stop reading;
			 break;
		}else if(data== -1 ){
			// print data
			printHeap(minHeap);                 
		}
		else{
			if(data > minHeap.top()){
				minHeap.pop();
				minHeap.push(data);
			}
		}
	}

	return 0;
}