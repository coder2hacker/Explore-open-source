using namespace std;
#include <iostream> 


 
    int firstO(int a[], int n, int x){
        int first = 0, last = n-1;
        while(first <= last){
            int mid = (first + last/2);
            if (a[mid] < x){
                first = mid + 1;
            } else if (a[mid] > x){
                last = mid - 1;
            } else {
                if ( mid == 0 || a[mid] != a[mid-1]){
                return mid;
                } else {
                    last = mid - 1;
                }

            }
        }
        return -1;
    }
    int lastO(int a[], int n, int x){
        int first = 0, last = n-1;
        while(first <= last){
            int mid = (first + last)/2;
            if (a[mid] < x){
                first = mid + 1;
            } else if (a[mid] > x){
                last = mid - 1;
            } else {
                if ( mid == n-1 || a[mid+1] != a[mid]){
                return mid;
                } else {
                    first = mid + 1;
                }
            }
        }
        return -1;
    }

int main(){
    int z[6] = {10,10,20,20,20,30}, n = 6, x = 20;
    int a,b;
    a = lastO(z,n,x);
    b = firstO(z,n,x);
    cout<<((a-b)+1);
    return 0;
}