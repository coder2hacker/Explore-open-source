using namespace std;
#include <iostream> 
#include <unordered_map> 

int longSubArrsum(int arr[], int n, int x){
    unordered_map<int,int> m;
    int curr = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        curr += arr[i];
        if (curr == x)
        {
            res = i+1;
        }
        if (m.find(curr) == m.end())
        {
            m.insert({curr,i});
        }
        if (m.find(curr-x) != m.end())
        {
            res = max(res, i-m[curr-x]);
        }
    }
    return res;
}

int subArray0(int arr[], int n){
    unordered_map<int,int> m;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == 0){
            arr[i] = -1;
        }
    }
    return longSubArrsum(arr,n,0);
}

int main(){
    int arr[] = {1,1,0,1,1,0,0}; int n = 7;
    cout<<subArray0(arr,n);
}