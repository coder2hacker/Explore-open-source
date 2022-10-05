#include<iostream>
using namespace std;
// To find gap between elements
int getNextGap(int gap)
{
    // Shrink gap by Shrink factor(1.3=13/10)
    gap = (gap*10)/13;
 
    if (gap < 1)
        return 1;
    return gap;
}

// Function to sort a[0..n-1] using Comb Sort
void combSort(int a[], int n)
{
    // Initialize gap
    int gap = n;
 
    /* Initialize swapped as true to make sure that
     loop runs
     */
    bool swapped = true;
 
    /* Keep running while gap is more than 1 and last
     iteration caused a swap
     */
    while (gap != 1 || swapped == true)
    {
        // Find next gap
        gap = getNextGap(gap);
 
        /* Initialize swapped as false so that we can
         check if swap happened or not
         */
        swapped = false;
 
        // Compare all elements with current gap
        for (int i=0; i<n-gap; i++)
        {
            if (a[i] > a[i+gap])
            {
                swap(a[i], a[i+gap]);
                swapped = true;
            }
        }
    }
}

// Driver function
int main()
{
    cout<< "Given Array: ";
    int a[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    int n = sizeof(a)/sizeof(a[0]);
    for (int i=0; i<n; i++)
        cout << a[i] <<" ";
    
    cout << endl;
    combSort(a, n);
 
    cout << "Sorted array: ";
    for (int i=0; i<n; i++)
        cout << a[i] <<" ";
    cout << endl;
 
    return 0;
}