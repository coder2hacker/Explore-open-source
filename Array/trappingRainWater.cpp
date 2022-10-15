using namespace std;
#include <iostream> 

int tappingWater(int arr[], int n){
    int lmax[n];
    int rmax[n];
    int res = 0;
    lmax[0] = arr[0];
    rmax[n-1] = arr[n-1];
    for(int i = 1;i < n-1;i++) lmax[i] = max(arr[i],lmax[i-1]);
    for(int i = n-2; i >= 0; i--) rmax[i] = max(arr[i],rmax[i+1]);
    for(int i = 0; i < n; i++) res = res + (min(rmax[i],lmax[i])-arr[i]);

    return res;
}

int main(){
 
}