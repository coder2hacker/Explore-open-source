using namespace std;
#include <iostream>
#include <cmath>

int search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1,6,5,8,3}, x = 5;
    cout<<search(arr, 5, x);
    
}