#include "bits/stdc++.h"
using namespace std;
int maxArea(int height[],int n) 
    {
        int i,j;
        
        i=0;
        j=n-1;
        int area = INT_MIN;
        while(i<j)
        {
            area = max(area,min(height[i],height[j])*(j-i));
            if(height[j]>height[i])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return area;
    }
int main(){
    int n;
    cin >>n;
    int nums[n];
    for(int i=0; i<n; i++){
        cin >> nums[i] ;
    }
    int res=maxArea(nums,n);
    cout<< res <<endl;
    return 0;
}