//Find maximum sum subarray

using namespace std;
#include <iostream> 

int maxSumsubArray(int arr[], int n){
    int curSum = 0;
    int maxSum = arr[0];
    for (int i = 0; i < n; i++)
    {
        curSum = curSum + arr[i];
        if(curSum > maxSum){
            maxSum = curSum;
        }
        if(curSum < 0){
            curSum = 0;
        }
    }
    return maxSum;   
}

int main(){
    int arr[] = {5,-4,-2,6,-1}, n = 5;
    cout<<maxSumsubArray(arr,n);
}