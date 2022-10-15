// time complexity = O(n^2)
//stable
// auxilary space = O(1)
// it is the most popular and most sufficient for small sized arrays

using namespace std;
#include <iostream> 

void insertionS(int arr[], int n){
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key; // yaha j ki value -1 aayegi
    }
    
}

int main(){
    int a[] = {2, 1, 3, 4};
	insertionS(a, 4);
	for(int i = 0;i < 4; i++){
	    cout<<a[i]<<" ";
	}
	return 0;
}