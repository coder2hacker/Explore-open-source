#include <bits/stdc++.h>
using namespace std;

// Main function to run the program
int main() 
{ 
    int arr[] = {10, 30, 10, 20, 40, 20, 50, 10}; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    int visited[n], count_dis=0;

    for(int i=0; i<n; i++){

        if(visited[i]!=1){
           for(int j=i+1; j<n; j++){
              if(arr[i]==arr[j]){
                 visited[j]=1;
              }
            }
             count_dis++;
         }
     }
    cout<<count_dis;
    return 0; 
}
