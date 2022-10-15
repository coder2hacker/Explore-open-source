using namespace std;
#include <iostream> 

int duplicate(int arr[], int n){
   for(int i = 0; i < n; i++){
       arr[arr[i]%n] += n;
   }
   for(int i = 0; i < n; i++){
       if(arr[i]/n > 1) cout<<i<<" ";
   }
   return -1;
}

int main(){
    int arr[] = {1,2,3,3,2,3}, n = 6;
    duplicate(arr,n);
}