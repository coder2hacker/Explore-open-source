#include<iostream>
using namespace std;

void bubble_sort(int arr[],int n){
    for(int i=0;i<n;i++){
        bool swapped=false;
        for(int j=1;j<n-i;j++){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
                swapped=true;
            }
        }
        if(swapped==false){
            break; 
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
    bubble_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}
