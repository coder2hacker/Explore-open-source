using namespace std;
#include <iostream> 

int maxConsecutive1(bool arr[], int n){
    int res = 0;
    for(int i = 0; i < n; i++){
        int curr = 0;
        if(arr[i] == 0) curr = 0;
        else {
            curr++;
            res = max(res,curr);
        }
    }
    return res;
}

int main(){
 
}