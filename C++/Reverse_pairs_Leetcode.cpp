class Solution {
public:
        #define ll long long
        int pairs=0;
        void merge(vector<ll>&arr, int l, ll mid, int h)
    {
        // Your code here
        //have been given two arrays from l to mid and mid + 1 to h
        ll tmp[h-l + 1];
        //merge from mid + 1 to h and l to mid
        int i=l,j=mid+1;
        int k=0;
        
        while(i<=mid and j<=h){
            if(arr[i]<=arr[j]){
                pairs += (lower_bound(arr.begin()+mid+1,arr.begin()+h+1,arr[i]/2) - (arr.begin()+mid+1));  //As the reverse pairs are counted when i < j so it would be counted 
                //only while we are traversing in the left part of the array.
                tmp[k++] = arr[i++];  
            }else{
                tmp[k++] = arr[j++]; 
            }
        }
        while(j<=h){
            tmp[k++] = arr[j++];
        }
    
        while(i<=mid){
            pairs += (lower_bound(arr.begin()+mid+1,arr.begin()+h+1,arr[i]/2) - (arr.begin()+mid+1));  //As the reverse pairs are counted when i < j so it would be counted 
            //only while we are traversing in the left part of the array.
            tmp[k++] = arr[i++];
        }
    
        //store from l to h in arr
        for(int i=l;i<=h;++i)
        arr[i] = tmp[i-l];
    }
    public:
    void mergeSort(vector<ll>&arr, int l, int h)
    {
        //code here
        if(l<h){
            ll mid = ((ll)l+h)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,h);
            merge(arr,l,mid,h);
        }
    }
    
    int reversePairs(vector<int>& nums) 
    {
        vector<ll> arr(nums.size());
        for(int i=0;i<nums.size();++i)
            arr[i] = 2ll*nums[i];
        mergeSort(arr,0,nums.size()-1);
        return pairs;
    }
};
