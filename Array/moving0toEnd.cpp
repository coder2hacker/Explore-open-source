using namespace std;
#include <iostream> 
#include <cmath> 

void move0(int arr[], int n){
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[a]);
            a++; 
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}        

int main(){
    int arr[] = {8, 5, 0, 10, 0, 20}, n = 6;
    move0(arr, n);
}