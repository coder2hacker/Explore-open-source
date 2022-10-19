//Program by Swaraj Shelavale @erroless111

#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


//User function template for C++
class Solution{
public:	
	void immediateSmaller(int *a, int n) {
	    //  code here
	    stack<int> s;
	    int i;
	    for(i=0;i<n-1;i++)
	    {
	        if(a[i]>a[i+1])
	        {
	            s.push(a[i+1]);
	        }
	        else
	        {
	            s.push(-1);
	        }
	    }
	    s.push(-1);
	    for(int i = n-1;i>=0;i--)
	    {
            a[i] = s.top();
            s.pop();
        }
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.immediateSmaller(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
