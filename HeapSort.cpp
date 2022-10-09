#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n,int i) // for maxheap
{
    int largest = i;
    int left=2*i;
    int right=2*i+1;

    if(left<=n && arr[largest]<arr[left])
        largest=left;
    if(right<=n && arr[largest]<arr[right])
        largest=right;
    if (largest!=i)
    {
        swap(arr[i],arr[largest]);
        i=largest;
    }
    else
        return;
}

void heapSort(int arr[], int n,int i)
{
    if(n==1)
        return;
    // Step 1: heapify the remaining elements(from n/2 to 1)
    for (int i = n/2; i >= 1; i--)
        heapify(arr,n,i);

    // Step 2:swap first(root) and last element as root element is always maximum(already sorted) in maxheap
    swap(arr[i],arr[n]);    

    // Step 3:As first(root) element is already sorted, so decreasing Size after swapping
    n--;

    // Step 4:Recursive call for sorting remaining elements
    heapSort(arr,n,i);
}

int main()
{
    int arr[]={-1,2,6,8,3,7};
    int n=5;

    heapSort(arr,n,1);
    
    for (int i = 1; i <= n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}
