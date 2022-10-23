

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       int sum=0;
        for(int i=0;i<k;++i){
            sum+=nums[i];
        }
        double total=sum;
        for(int j=k;j<nums.size();++j){
            sum-=nums[j-k];
            sum+=nums[j];
            if(sum>total){
                total=sum;
            }
        }
        return total/k;
    }
};
