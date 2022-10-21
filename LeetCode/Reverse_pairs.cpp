int reversePairs(vector<int> &arr, int n) {
	int pairs = 0;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (arr[i] > 2 * arr[j])
				pairs++;
		}
	}
	return pairs;
}