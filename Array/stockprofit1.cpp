using namespace std;
#include <iostream> 

int profit(int arr[], int n){
    int curr = INT_MAX;
    int profit = 0;
    int i = 0;
    for(int i = 0; i < n; i++){
        if(curr > arr[i]) curr = arr[i];
        else if (arr[i]-curr > profit) profit = arr[i] - curr;
    }
    return profit;
}
int main(){
  int arr[6] = {7,1,5,3,6,4};
  cout<<profit(arr,6);
}