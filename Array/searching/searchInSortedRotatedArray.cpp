using namespace std;
#include <iostream> 

int search(int arr[], int n, int x){
    int first = 0, last = n-1;
    while(first <= last){
        int mid = (first + last)/2;
        if(arr[mid] == x){
            return mid;
        }
        if(arr[first] < arr[mid]){
            if(arr[first] <= x && arr[mid] > x){
                last = mid - 1;
            } else {
                first = mid + 1;
            }
        } else {
            if (arr[mid] < x && arr[last] <= x){
                first = mid + 1;
            } else {
                last = mid -1;
            }
        }
    }
    return -1;
}

int main(){
    int a[6] = {10, 20, 40, 5, 8}, n = 6, x =  5;
    cout<<search(a,n,x);
}