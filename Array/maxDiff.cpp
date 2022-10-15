using namespace std;
#include <iostream> 

int maxDiff(int arr[], int n){
    int a = arr[1] - arr[0], b = arr[0];
    for (int i = i; i < n; i++)
    {
        a = max(a, (arr[i] - b));
        b = min(b, arr[i]);
    }
    return a;
} 

int main(){
    int arr[] = {2, 3, 10, 6, 4, 8, 1}, n = 7;
    cout<<maxDiff(arr, n);
}