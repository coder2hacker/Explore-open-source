using namespace std;
#include <iostream> 

void count(int arr[], int n){
   int f = 1;
   int i = 1;
   while(i < n){
       while(i < n && arr[i] == arr[i-1]){
           f++;
           i++;
       }
       cout<<arr[i-1]<<" "<<f<<endl;
       i++;
       f = 1;
    if (n ==1 || arr[n-1] != arr[n-2]){
       cout<<arr[n-1]<<" "<<f;
   }
   }
}

int main(){
    int arr[] = {10, 10, 10, 25, 30, 30}, n = 6;
    count(arr, n);
}
