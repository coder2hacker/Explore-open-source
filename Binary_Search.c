#include <stdio.h>
 
// Recursive implementation of the binary search algorithm to return
// the position of target `x` in subarray `A[low…high]`
int binarySearch(int A[], int low, int high, int x)
{
    // Base condition (search space is exhausted)
    if (low > high) 
	{
        return -1;
    }
 
    // find the mid-value in the search space and
    // compares it with the target
 
    int mid = (low + high)/2;    // overflow can happen
    // int mid = low + (high - low)/2;
 
    // Base condition (target value is found)
    if (x == A[mid]) 
	{
        return mid;
    }
 
    // discard all elements in the right search space,
    // including the middle element
    else if (x < A[mid]) 
	{
        return binarySearch(A, low, mid - 1, x);
    }
 
    // discard all elements in the left search space,
    // including the middle element
    else 
	{
        return binarySearch(A, mid + 1, high, x);
    }
}
 
int main(void)
{
    int A[20],i,num;
    printf("\nEnter the range of the array:");
    scanf("%d",&num);
    printf("\nEnter %d number of elements:",num);
    for(i=0;i<=num;i++)
    {
    	scanf("%d",&A[i]);
	}
 
    int n = sizeof(A)/sizeof(A[0]);
 
    int low = 0, high = n - 1;
    int index = binarySearch(A, low, high, target);
 
    if (index != -1) 
	{
        printf("Element found at index %d", index);
    }
    else 
	{
        printf("Element not found in the array");
    }
 
    return 0;
}
