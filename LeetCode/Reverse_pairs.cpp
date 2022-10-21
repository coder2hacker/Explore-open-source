#include <bits/stdc++.h>
int merge(vector<int>&arr, int l, int mid, int h) {
	int pairs = 0;
	int tmp[h - l + 1];
	int i = l, j = mid + 1, k = 0;
	while (i <= mid and j <= h) {
		if (arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else { 
			//Here we can't directly give the condition that if arr[i] > 2*arr[j] then increment the no of pairs because it might happen that for this element arr[i] < 2*arr[j] but there might exist elements to the right of arr[i] are greater than 2*arr[j]. 
			int ub = upper_bound(arr.begin() + l, arr.begin() + mid + 1, 2 * arr[j]) - arr.begin();
			pairs += (mid + 1 - ub);
			tmp[k++] = arr[j++];
		}
	}
	while (i <= mid)
		tmp[k++] = arr[i++];

	while (j <= h) {
		int ub = upper_bound(arr.begin() + l, arr.begin() + mid + 1, 2 * arr[j]) - arr.begin();
		pairs += (mid + 1 - ub);
		tmp[k++] = arr[j++];
	}

	for (int i = l; i <= h; ++i)
		arr[i] = tmp[i - l];

	return pairs;
}

int mergeSort(vector<int>&arr, int l, int h) {
	//Total number of reverse pairs would be the summation of pairs from the left
	//half ,the right half and when they both are being merged.
	int pairs = 0;
	if (l < h) {
		int mid = l + (h - l) / 2;
		pairs += mergeSort(arr, l, mid);
		pairs += mergeSort(arr, mid + 1, h);
		pairs += merge(arr, l, mid, h);
	}
	return pairs;
}

int reversePairs(vector<int> &arr, int n) {
	return mergeSort(arr, 0, n - 1);
}
