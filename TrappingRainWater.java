  public int trap(int[] height) {
        int[] left = new int[height.length]; //for left most height for every tower
        int[] right = new int[height.length]; //for right most height for every tower
        int n = height.length;
        
        int ctr = height[0];
        for(int i =0; i<n; i++){
            ctr = Math.max(ctr,height[i]);
            
            left[i] = ctr;
        }
        
        ctr = height[n-1];
        for(int i =n-1; i>=0; i--){
            ctr = Math.max(ctr,height[i]);
            right[i] = ctr;
        }
        int res = 0;
        
        for(int i =0; i<n; i++){
            res += Math.min(left[i], right[i])-height[i];//water for every tower
        }
        
        return res;
    }
