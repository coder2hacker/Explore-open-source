//Binary Searchwith Recursion 

#include<stdio.h> 
#include<conio.h>
int binarySearch(int arr[], int l, int r, int x) 
{ 
if (r >= l) 
{ 
		int mid = l + (r - l)/2; 
        if (arr[mid] == x) return mid; 
		if (arr[mid] > x) return binarySearch(arr, l, mid-1, x); 
		return binarySearch(arr, mid+1, r, x); 
} 
return -1; 
} 
void main()
{ 
int arr[100],n,x,c,s;
  printf("Enter the range of the elements:\n");
	scanf("%d",&s);
	printf("Enter %d integers:\n",s);
	for(c=0;c<s;c++)
		scanf("%d",&arr[c]);
  printf("\nThe Array is:\n");
  for(c=0;c<s;c++)
    printf("%d ",arr[c]);
  printf("\nEnter Number to find:");
  scanf("%d",&x); 
  int result = binarySearch(arr, 0, s, x);
(result == -1)? printf("Element is not present in array") 
				: printf("Element is present at index %d", result); 
getch(); 
}
