#include <iostream>
using namespace std;

int binSearch(int arr[], int x, int start, int end)
{
    if (start > end)
        return -1;

    int mid = (start + end) / 2;

    if (arr[mid] == x)
        return mid;

    else if (arr[mid] > x)
    {
        end = mid - 1;
        return binSearch(arr, x, start, end);
    }
    else
    {
        start = mid + 1;
        return binSearch(arr, x, start, end);
    }
}

int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int start;
    cin >> start;
    cout << binSearch(arr, start, 0, sizeof(arr) / 4);
    return 0;
}