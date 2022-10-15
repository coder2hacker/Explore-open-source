//Find the common elements in two arrays

using namespace std;
#include <iostream> 

void common(int a[], int b[], int m, int n){
    int i=0,j=0;
    while(i<m && j<n){
        if(i>0 && a[i-1]==a[i]){
            i++;
            continue;
        }
        if(a[i]<b[j]){
            i++;
        }
        else if(a[i]>b[j]){
            j++;
        }
        else{
            cout<<a[i]<<" ";
            i++;j++;
        }
    }    
}

int main(){
    int a[] = {10,20,20,40,60}, b[] = {2,20,20,20};
    common(a,b,5,4);
}