using namespace std;
#include <iostream>
#include <unordered_set>

bool subSum(int arr[], int n, int x){
    unordered_set<int> s;
    for(int i = 0; i < n; i++){
        int m = x - arr[i];
        if(s.find(m) != s.end()){
            return true;
        } else {
            s.insert(arr[i]);
        }
    }
    return false;
}

int main(){
    int arr[] = {8,3,4,2,5};
    cout<<subSum(arr,5,6);
}