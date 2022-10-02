#include <bits/stdc++.h>
using namespace std;

void leftRotateArray(int arr[], int r, int n)
{
    r = r % n;
    if (r == 0)
        return;
    reverse(arr + 0, arr + r);
    reverse(arr + r, arr + n);
    reverse(arr + 0, arr + n);
}

void rightRotateArray(int arr[], int r, int n)
{
    r = r % n;
    if (r == 0)
        return;
    reverse(arr + (n-r), arr + n);
    reverse(arr + 0, arr + (n-r));
    reverse(arr + 0, arr + n);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main()
{
    int n, i, r;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements " << endl;
    for (i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the Rotating Factor: ";
    cin >> r;
    cout<<"Left Rotated"<<endl;
    leftRotateArray(arr, r, n);
    printArray(arr, n);
    cout<<"Right Rotated"<<endl;
    rightRotateArray(arr, r, n);
    printArray(arr, n);
    return 0;
} 
