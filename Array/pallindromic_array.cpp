class Solution {
public:
    int PalinArray(int a[], int n)
    {
    	// code here
    	for(int i =0; i<n; i++){
    	    int ans = 0;
    	    int temp = a[i];
    	    
    	    while(temp>0){
    	        int r = temp%10;
    	        
    	        temp/=10;
    	        
    	        ans = (ans*10)+r;
    	    }
    	    
    	    if(ans!=a[i])
    	    return 0;
    	}
    	return 1;
    }   	
};