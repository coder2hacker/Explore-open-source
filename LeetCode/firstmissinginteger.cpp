#include <iostream>
using namespace std;
int first(int nums[],int n) {
    for (int j = 0; j < n - 1; j++){
    if (nums[j] > nums[j + 1]){
        int temp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = temp;
        j = -1;
        }
    }
        int z=1;
        for(int i=0; i<n; i++){
            if(nums[i]==z){z++;}
        } 
        return z;
}
int main(){
    int n;
    cin >>n;
    int nums[n];
    for(int i=0; i<n; i++){
        cin >> nums[i] ;
    }
    int res=first(nums,n);
    cout<< res <<endl;
    return 0;
}