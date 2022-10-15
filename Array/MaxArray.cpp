using namespace std;
#include <iostream> 

int max(int arr[], int n){
    int res=0;
    for (int i = 0; i < n; i++)
    {
       if ( arr[i] > arr[res])
       {
           res = i;
       } 
    }  
    return res;
}    

int main(){
    int arr[] = {2,5,8,4}, n = 4;
    cout<<max(arr,n);
}