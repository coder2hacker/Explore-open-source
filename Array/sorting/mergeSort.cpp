// stable algorithm
// time complexity = theta(nlogn) and O(n) Aux space
// well suited for linked list, works in O(1) space
// in case of array quick sort is better than merge sort

using namespace std;
#include <iostream> 

void merge(int A[], int mid, int low, int high)
{
    int i, j, k;
    int*B = new int[high+1];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high){
        if (A[i] < A[j]){
            B[k] = A[i];
            i++;
            k++;
        }
        else{
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid){
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high){
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++){
        A[i] = B[i];
    }
}

void mergeSort(int A[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}

int main(){
    int arr[7] = {9,4,7,6,3,1,5};
    mergeSort(arr,0,6);
    for (int i = 0; i < 7; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}