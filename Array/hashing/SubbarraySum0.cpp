#include <iostream>
#include <unordered_set>
using namespace std;

bool ZeroSumSubarray(int arr[], int n)
{
    unordered_set<int> s;
    int curr_sum = 0;
    s.insert(0);
    for(int i = 0; i < n; i++)
    {
        curr_sum += arr[i];
        if(s.find(curr_sum) != s.end()){
          return true;
        }
          s.insert(curr_sum);
    }
    return false;
}

int main()
{
    int arr[] = {3,4,-3,-1,1};
    int n = 5;
    
    cout << ZeroSumSubarray(arr, n);
}