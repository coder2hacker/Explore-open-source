#include<iostream>
#include<vector>
using namespace std;
 int pivotIndex(vector<int>& nums) {
        
        int n=nums.size(),s=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
            nums[i]=s;
        }
        if(s-nums[0]==0){
            return 0;
        }

        for(int i=1;i<n;i++){
            int t= s-nums[i];
            if(nums[i-1]==t){
                return i;
            }
        }

        

        return -1;
    }
int main(){

    int n;
    cin>>n;

    vector<int> ar;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        ar.push_back(a);
    }

    cout<<pivotIndex(ar);
}
   
