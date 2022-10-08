//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void segregateElements(int arr[], int n)
    {
        // Your code goes here
        int temp;
        for (int i = 0; i < n; i++)
        {

            if (arr[i] < 0)
            {
                temp = arr[i];
                for (int j = i; j < n; j++)
                    arr[j] = arr[j + 1];
            }
            arr[n - 1] = temp;
            for (int k = 0; k < n; k++)
                cout << arr[k] << " ";
            cout << endl;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        ob.segregateElements(a, n);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}

// } Driver Code Ends