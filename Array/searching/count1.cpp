using namespace std;
#include <iostream> 

int count1(int arr[], int n){
    int first = 0, last = n-1;
    while(first<=last){
        int mid = (first + last)/2;
        if(arr[mid] == 0){
            first = mid +1;
        } else {
            if(mid == 0 || arr[mid-1] != arr[mid]){
                return (n-mid);
            } else {
                last = mid - 1;
            }
        }
    }
    return 0;
}

int main(){
    int a[6] = {0,0,1,1,1,1}, n = 6;
    cout<<count1(a,n);
}