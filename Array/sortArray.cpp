using namespace std;
#include <iostream> 

int isSort(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        if(arr[i+1] < arr[i]){
            return false;
        }
    }
    return true;
}

int main(){
    int arr[] = {2,4,6,9}, n = 4;
    cout<<isSort(arr,n);
}