//time complexity = theta(n^2);
//it does less memory writes compared to quick sort, insetion sort, merge sort etc. but cycle sort is optimal in terms of memory writes
//not stable

#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n){
    
    for(int i = 0; i < n; i++){
        int min = i;
        
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        
        swap(arr[i], arr[min]);
    }
    
    
}

int main() {
	int a[] = {2, 1, 3, 4};
	selectionSort(a, 4);
	for(int i = 0;i < 4; i++){
	    cout<<a[i]<<" ";
	}
	return 0;
}