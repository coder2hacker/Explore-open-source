// Find if there is a pair whose sum is X in an sorted array
//two pointer approach
//it is best in case of sorted array
//in case of unsorted hashing is better

using namespace std;
#include <iostream> 

bool Sum(int arr[], int n, int x){
    int f = 0, l = n-1;
    while(f <= l){
        int s = arr[f] + arr[l];
        if(s > x){
            l--;
        } else if(x > s){
            f++;
        } else {
            return true;
        }
    }
    return false;
}

int main(){
    int arr[8] = {2,4,8,9,11,12,20,30}; 
    cout<<Sum(arr,8,23);
}