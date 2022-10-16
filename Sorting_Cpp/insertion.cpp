#include<iostream>
using namespace std;

void insertion_sort(int arr[],int n){
    int j;
    for(int i=1;i<n;i++){
        int temp=arr[i];
        for(j=i-1;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]=temp;
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
    insertion_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}