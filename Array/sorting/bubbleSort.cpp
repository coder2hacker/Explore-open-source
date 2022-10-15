using namespace std;
#include <iostream> 

// time complexity = O(n^2)
//stable
void bubbleS(int arr[], int n){
    bool swapped;
    for (int i = 0; i < n-i-1; i++)
    {
        swapped = false;
        for (int j = 0; j < n-1; j++)
        {
            if(arr[j+1] < arr[j]){
                swap(arr[j+1], arr[j]);
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        }
    } 
}

int main(){
    int arr[5] = {6,2,8,4,9}, n = 5;
    bubbleS(arr,n);
    for(int i : arr){
        cout<<i<<" ";
    }
}