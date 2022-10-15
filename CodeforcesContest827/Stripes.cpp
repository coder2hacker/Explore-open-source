#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int c;
        char a[8][8], cl;
        vector<int> h, v;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cin >> a[i][j];
            }
        }

        for (int i = 0; i < 8; i++)
        {
            if (a[0][i] == 'R' || a[0][i] == 'B')
            {
                h.push_back(i);
            }
        }
        for (int i = 0; i < 8; i++)
        {
            if (a[i][0] == 'R' || a[i][0] == 'B')
            {
                v.push_back(i);
            }
        }

        for (int x : h)
        {
            c = 0;
            for (int i = 0; i < 7; i++)
            {
                if (a[i][x] == a[i + 1][x])
                    c++;

                if (c == 7)
                    cl = a[i][x];
            }
        }
        for (int x : v)
        {
            c = 0;
            for (int i = 0; i < 7; i++)
            {
                if (a[x][i] == a[x][i + 1])
                    c++;

                if (c == 7)
                    cl = a[x][i];
            }
        }
        cout << cl << "\n";
    }
    return 0;
}