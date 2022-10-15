using namespace std;
#include <iostream> 

void Union(int a[], int b[], int m, int n){
    int i=0,j=0;
    while(i<m && j<n){
        if(i>0 && a[i-1]==a[i]){
            i++;
            continue;
        }
        if(j>0 && b[j-1]==b[j]){
            j++;
            continue;
        }
        if(a[i]<b[j]){
            cout<<a[i]<<" ";
            i++;
        }
        else if(a[i]>b[j]){
            cout<<b[j]<<" ";
            j++;
        }
        else{cout<<a[i]<<" ";
        i++;
        j++;
        }
    }
        while(i<m){
            if(i==0||a[i]!=a[i-1])
            cout<<a[i]<<" ";
            i++;
        }
        while(j<n){
            if(j==0||b[j]!=b[j-1])
            cout<<b[j]<<" ";
            j++;
        }
}

int main(){
    int a[]={2,10,10,30};
    int b[]={1,1,2,3,4,8};

    Union(a,b,4,6);

    return 0;
}