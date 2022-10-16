#include<iostream>
using namespace std;
void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
            swap(arr[min_index],arr[i]);
        }
    }
}
//driver code
int main(){
    int n;
    cout<<"enter the sixze of array";
    cin>>n;
    int * arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selection_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}
