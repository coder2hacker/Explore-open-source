using namespace std;
#include <iostream> 

int insert(int arr[], int n, int cap, int a, int pos){
    if(cap == n){
        return 0;
    }
    for(int i = n-1; i >= (pos-1); i--){
        arr[i+1] = arr[i];
    }
    arr[(pos-1)] = a;

    for (int i = 0; i < cap; i++)
    {
        cout<<arr[i]<<" ";
    }   
}

int main(){
    int arr[] = {2,3,7,9}, n = 4, cap = 5, a = 5, pos = 2;
    insert(arr, n, cap, a, pos);
}