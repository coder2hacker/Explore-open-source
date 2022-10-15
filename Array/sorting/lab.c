#include <stdio.h>

void linearSearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            printf("The number %d is present at index %d", x, i);
            break;
        }
    }
}

void binarySearch(int arr[], int n, int x)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == x)
        {
            printf("The number %d is at index %d\n", x, mid);
            break;
        }
        else if (arr[mid] > x)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
}

int display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        int min = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        display(arr,n);
        printf("\n");
    }
}


int main()
{
    int n, i, x, j;
    printf("Enter the size of array\n");
    scanf("%d", &n);
    // int arr[n];
    // printf("Enter the elements of array\n");
    // for (i = 0; i < n; i++)
    // {
    //     scanf("%d", &arr[i]);
    // }
    // printf("Enter the number you want to find\n");
    // scanf("%d", &x);
    // printf("1. Linear Search\n2. Binary searxh\n");
    // int s;
    // scanf("%d", &s);
    // if(s==1){
    //     linearSearch(arr,n,x);
    // } else {
    //     binarySearch(arr,n,x);
    // }
    int arr1[n];
    printf("Enter the elements of array to be sorted\n");
    for (j = 0; j < n; j++)
    {
        scanf("%d", &arr1[j]);
    }
    printf("1. Bubble Sort\n2. Selection Sort\n");
    int q;
    scanf("%d", &q);
    if (q == 1)
    {
        bubbleSort(arr1, n);
        display(arr1, n);
    }
    else
    {
        selectionSort(arr1, n);
        display(arr1, n);
    }

    return 0;
}