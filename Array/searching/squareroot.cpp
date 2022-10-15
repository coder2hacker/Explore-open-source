// using namespace std;
// #include <iostream>
// #include <cmath>

// int main(){
//    cout<<sqrt(16);
// }

// using binary search

using namespace std;
#include <iostream> 

int sqRoot(int x){
    int first = 1, last  = x, ans = -1;
    while(first<=last){
        int mid = (first + last)/2;
        int midsq = mid * mid;
        if(midsq == x){
            return mid;
        } else if (midsq > x){
            last = mid -1;
        } else {
            first = mid + 1;
            ans = mid;
        }
    }
    return ans;
}

int main(){
    cout<<sqRoot(25);
    return 0;
}