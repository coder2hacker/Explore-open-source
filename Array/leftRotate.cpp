using namespace std;
#include <iostream>

void rotateL(int arr[], int n, int x){
    for (int i = 0; i < (n-2); i++)
    { 
        swap(arr[i+x], arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
        
}

int main(){
    int arr[] = {1, 2, 3, 4, 5}, n = 5;
    rotateL(arr,n,2);
}