#include <bits/stdc++.h>
using namespace std;

/*
Pigeonhole sorting is used when the number of values and range of values are approximately same.
Time Complexity : O(n + Range)
Space Complexity : O(n + Range)
To perform this sort we set up an empty array pigeonholes where size of array is determined by the range.
In each hole, items are inserted.
Finally deleted and stored into an array in sorted manner.
*/

void pigeonholeSort(int array[], int size)
{
    // We find maximum and minimum values in the array[]
    // 0-indexing is used here
    int max = array[0], min = array[0];
    for (int i = 0; i < size; i++)
    {
        if (max < array[i])
        {
            max = array[i];
        }
        if (min > array[i])
        {
            min = array[i];
        }
    }
    // We find range from calculated values of max and min.
    int range = max - min + 1;

    // We setup an array of vectors of size range.
    vector<int> holes[range];
    // We make an array of vectors and not a vector so as to store equal elements at the same position

    // Traverse through array and put every element in its
    // respective hole : holes[array[i] - min]
    for (int i = 0; i < size; i++)
    {
        holes[array[i] - min].push_back(array[i]);
    }

    // Now we traverse through all the holes and insert all elements of holes in sorted order
    int index = 0;
    for (int i = 0; i < range; i++)
    {
        // Use of auto keyword
        auto it = holes[i].begin();
        for (it; it != holes[i].end(); it++)
        {
            // store elements from non-empty holes in a sorted manner
            array[index] = *it;
            index++;
        }
    }
}

int main()
{

    int array[] = {2, 7, 4, 13, 17, 5, 8};
    int size = sizeof(array) / sizeof(array[0]);

    // Call to the function pigeonhole sort.
    pigeonholeSort(array, size);

    cout << "The array in sorted order is : \n";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}