using namespace std;
#include <iostream>

#include <unordered_set>
int firstRepeated(int arr[], int n)
{
    unordered_set<int> s, p;
    for (int i = 0; i < n; i++)
    {
        if (p.find(arr[i]) != p.end())
        {
            s.insert(arr[i]);
        }
        else
        {
            p.insert(arr[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s.find(arr[i]) != s.end())
        {
            return i + 1;
        }
    }
    return -1;
}


int main()
{
    int arr[7] = {1,5,3,4,3,5,6}, n = 7;
    cout<<firstRepeated(arr,n);
}