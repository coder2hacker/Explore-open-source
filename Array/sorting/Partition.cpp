//Partition mtlb jiss element ka index diya h uss element ke left m saare usse chote aur right m usse saare bade element lagao
// in the new array formed return the index of the given element

//both lamuto and hoare partition take time O(n) and O(1) space

//lomuto partition
//pivot or given index is always last element
//if pivot is given of any other index than last then just swap that index with last  
using namespace std;
#include <iostream> 

// int Lpartition(int arr[], int first, int last){
//     int i = first - 1;
//     int pivot = arr[last];
//     for (int j = first; j < last; j++)
//     {
//         if (arr[j] < pivot)
//         {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i+1], arr[last]);
//     return (i+1);
// }

//Hoare Parition
//it is much better than lamuto partition
//here we consider first element as pivot
//lekin iska bharosa ni h ki ye pivot element ko shi jagah dega, isliye lomuto is slightly bettter than hoare

int Hpartition(int arr[], int first, int last){
    int pivot = arr[first];
    int i = first - 1, j = last + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
        {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}

int main(){
    int arr[] = {10,80,30,90,40,50,70};
    //cout<<Lpartition(arr,0,6)<<endl;
    cout<<Hpartition(arr,0,6)<<endl;
    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i]<<" ";
    }
}



