#include<iostream>
#include<queue>
using namespace std;

class mycmp{
public:
	// return true when swap needed
	// b is a new node inserted in heap
	bool operator()(int a, int b){
		return b<a; // swap needed in min heap if b<a
	}
};

int main(){
	priority_queue<int, vector<int> ,mycmp> m;
	m.push(10);
	m.push(7);
	m.push(8);
	m.push(5);
	m.push(4);
	m.push(6);
	m.push(3);
	m.push(2);
	m.push(1);
	while(!m.empty()) {
		cout << m.top() << " ";
		m.pop();
	}
	return 0;
}