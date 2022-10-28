#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{ // row checker
    for (int row = 0; row < x; row++)
    {
        if (arr[row][y] == 1)
        {
            return false;
        }
    }
    // col checker
    // for (int col = 0; col < y; col++)
    // {
    //     if (arr[x][col] == 1)
    //     {
    //         return false;
    //     }
    // }
    // diagonal checking
    int row = x, col = y;
    while (row >= 0 and col >= 0)
    { // left diagonal check
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }
    row = x, col = y;
    while (row >= 0 and col < n)
    { // right diagonal check
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}

// no need of col here as we only need row
bool nKween(int **arr, int x, int n)
{
    // queens have been placed
    if (x >= n)
    {
        return true;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, x, col, n))
        {
            arr[x][col] = 1;
            if (nKween(arr, x + 1, n))
            {
                return true;
            }
            arr[x][col] = 0; // backtracking
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    if (nKween(arr, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
}
