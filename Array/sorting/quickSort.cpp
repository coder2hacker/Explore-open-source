// time complexity is O(nlogn)
// space complexity O(n)

using namespace std;
#include <iostream> 

int partition(int arr[], int l, int h){
    int i = l;
    int j = h;
    int pivot = arr[l]; //jab pivot pehla element lete hn tb O(n^2) hota h, worst case
    //int pivot = (l+h)/2; //isse (nlogn) time m krne ke liye humme pivot mid element ko lena padega, best case
    //random(l,h) = pivot; //isse average O(nlogn) aayega
    while(i < j){   
        while(arr[i] <= pivot) i++;
        while(arr[j] > pivot) j--;
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[l]);
    return j;
}

void quickS(int arr[], int l, int h){
    if(l < h){
        int pivot =  partition(arr,l,h);
        quickS(arr,l,pivot-1);
        quickS(arr,pivot+1,h);
    }
}

int main(){
    int arr[] = {4,6,2,5,7,9,1,3};
    quickS(arr,0,7);
    for (int i = 0; i < 8; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}