using namespace std;
#include <iostream> 
#include <unordered_set> 

void intersection(int a[], int b[], int n, int m){
    unordered_set<int> s;
    for(int i = 0; i < n; i++){
        s.insert(a[i]);
    }
    for(int i = 0; i < m; i++){
        if(s.find(b[i])!=s.end()) cout<<b[i]<<" ";
    }
}

int main(){
    int a[] = {1,6,3,8,2}, b[] = {2,6,8,5,9,3};
    intersection(a,b,5,6);
}