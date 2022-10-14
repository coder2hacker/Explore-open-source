class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, i=0, j=height.size()-1;
        
        while(i<j)
        {
            int x = min(height[i], height[j])*(j-i);
            ans = max(ans, x);
            if(height[i]<height[j])
            i++;
            else 
            j--;
        }
        return ans;
    }
};
