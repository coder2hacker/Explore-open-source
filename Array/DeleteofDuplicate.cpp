using namespace std;
#include <iostream> 

int dup(int arr[], int n){
    int a = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[a-1])
        {
            arr[a] = arr[i];
            a++;
        }
    }
    return a;
}

int main(){
    int arr[] = {10,20,20,30,30,30,30}, n = 7;
    cout<<dup(arr, n);
}