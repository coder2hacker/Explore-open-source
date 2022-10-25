#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
using namespace std;
 
bool similar(vector<int> &A, int k)
{
    unordered_map<int, int> map;
    for (int i = 0; i < A.size(); i++)
    {
        
        if (map.find(A[i]) != map.end())
        {
            
            if (i - map[A[i]] <= k) {
                return true;
            }
        }
        map[A[i]] = i;
    }
    return false;
}
int main()
{
    vector<int> A = { 5, 6, 8, 2, 4, 6, 9 };
    int k = 4;
 
    if (similar(input, k)) {
        cout << "Duplicates found";
    }
    else {
        cout << "No duplicates were found";
    }
 
    return 0;
}