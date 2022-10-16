#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ss, subarray;


void Index_subset (int num, int size, vector<int> subset) {
    if ( num > size ){
        ss.push_back(subset);
    }
   else {
       subset.push_back(num);
       Index_subset(num+1, size, subset);
       subset.pop_back();
       Index_subset(num+1, size, subset);
   }
}

int main() {

    cout<<"Enter any Number  x : ";
    int n; cin>>n;

    vector<int> v,v1(n);

    cout<<"\nEnter x numbers : ";
    for(int i=0; i<n; i++){cin>>v1[i];}

    Index_subset(0,n,v);
    printSubArrays(v1,0,0);

    cout<<"\n";

    for(auto h : ss){
        cout<<"[ ";
        for(int x : h){
            cout<<x<<" ";
        }
        cout<<"] ";
    }

}
