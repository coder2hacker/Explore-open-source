using namespace std;
#include <iostream> 

void reverse(int arr[], int n){
    int first = 0, last = n-1;
    while(first < last){
        int a = arr[first];
        arr[first] = arr[last];
        arr[last]= a;
        first++;
        last--;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main(){
    int arr[] = {10, 5, 7, 30}, n = 4;
    reverse(arr, n);
}