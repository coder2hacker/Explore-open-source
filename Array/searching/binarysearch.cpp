//normal tareeka

using namespace std;
#include <iostream> 

int search(int arr[], int n, int x){
    int first = 0, last = n - 1;
    int mid;
    while(first <= last){
        mid = (first + last)/2;
        if(arr[mid] == x){
            return mid;
        } else if (arr[mid] < x){
            first = mid +1;
        } else {
            last = mid -1;
        }
    }
    return -1;
}

int main(){
    int a[8] = {2,4,8,10,11,12,15,20}, n = 8, x = 15;
    cout<<search(a,n,x);
}

