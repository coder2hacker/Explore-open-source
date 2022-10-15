// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
// Function to find maximum distinct
// character after removing K character
int maxDistinctChar(string s, int n, int k)
{
	// Freq implemented as hash table to
	// store frequency of each character
	unordered_map<int, int> freq;

	// Store frequency of each character
	for (int i = 0; i < n; i++)
		freq[s[i]]++;

	vector<int> v;

	// Insert each frequency in v
	for (auto it = freq.begin();
		it != freq.end(); it++) {
		v.push_back(it->second);
	}

	// Sort the freq of character in
	// non-decreasing order
	sort(v.begin(), v.end());

	// Traverse the vector
	for (int i = 0; i < v.size(); i++) {
		int mn = min(v[i] - 1, k);

		// Update v[i] and k
		v[i] -= mn;
		k -= mn;
	}

	// If K is still not 0
	if (k > 0) {

		for (int i = 0; i < v.size(); i++) {
			int mn = min(v[i], k);
			v[i] -= mn;
			k -= mn;
		}
	}

	// Store the final answer
	int res = 0;
	for (int i = 0; i < v.size(); i++)

		// Count this character if freq 1
		if (v[i] == 1)
			res++;

	// Return count of distinct characters
	return res;
}

// Driver Code
int main()
{
	// Given string
	string S = "bobisbobbydeol";

	int N = S.size();

	// Given k
	int K = 1;

	// Function Call
	cout << maxDistinctChar(S, N, K);

	return 0;
}
