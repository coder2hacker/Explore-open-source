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

int SumLenght(int arr1[], int arr2[], int n){
    int temp[n];
    for(int i = 0; i < n; i++){
        temp[i] = arr1[i] - arr2[i];
    }
    return longSubArrsum(temp,n,0);
}

int main(){
    int arr1[] = {0,1,0,0,0,0}, arr2[] = {1,0,1,0,0,1}, n = 6;
    cout<<SumLenght(arr1,arr2,6);
}