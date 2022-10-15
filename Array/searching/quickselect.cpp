#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int h){
    int i = l;
    int j = h;
    int pivot = arr[l]; 
    while(i <= j){   
        while(arr[i] <= pivot) i++;
        while(arr[j] > pivot) j--;
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[l]);
    return j;
}

int kthSmallest(int arr[], int l, int r, int k)
{
	if (k > 0 && k <= r - l + 1) {
		int index = partition(arr, l, r);
		if (index - l == k - 1)
			return arr[index];
		if (index - l > k - 1)
			return kthSmallest(arr, l, index - 1, k);
        else return kthSmallest(arr, index + 1, r,k - index + l - 1);
	}
	return INT_MAX;
}

int main()
{
	int arr[] = { 10, 4, 5, 8, 6, 11, 26 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	cout << "K-th smallest element is "
		<< kthSmallest(arr, 0, n - 1, k);
	return 0;
}
