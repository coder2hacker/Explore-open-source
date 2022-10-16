#include<bits/stdc++.h>
using namespace std;

void find (int arr[], int n)
{
  int result = -1;
  
  for(int i=0; i<n; i++){
    
    int left_sum =0;
    for(int j=0; j<i; j++)
       left_sum += arr[i];
    int right_sum =0;
    for(int j=i+1; j<n; j++)
       right_sum += arr[i];
    
    if(right_sum == left_sum)
    result = i;
      
  }
  
    cout<<"First Point of equilibrium is at index = "<<result;
    return;
  
}

int main ()
{
  int arr[]={4, -2, 0, 6, -4};
  int n = sizeof(arr)/sizeof(arr[0]);

  find (arr, n);
  return 0;
}
