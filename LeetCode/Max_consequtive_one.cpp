#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int findMaxConsecutiveOnes(int nums[],int n) {
        // sort(nusm.begin(),nums.end());
        int count =0,maxi=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                count++;
            }
            else{
                count=0;
            }
            maxi=max(count,maxi);
        }
        return maxi;
    }

//driver code
int main(){
    int n;
    cout<<"Enter the size of array";
    cin>>n;
    int arr[n];
    //taking input in the array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   int ans= findMaxConsecutiveOnes(arr,n);
   cout<<ans<<endl;

    return 0;

}