#include <bits/stdc++.h>
using namespace std;

void prime_seive(int n)
{
    int i, j;
    int seive[n] = {0};
    for (i = 2; i * i <= n; i++)
    {
        if (seive[i] == 0)
        {
            for (j = i * i; j <= n; j += i)
            {
                seive[j] = 1;
            }
        }
    }
    cout << "The Prime number from 1 to " << n << " are : ";
    for (i = 2; i <= n; i++)
    {
        if (seive[i] == 0)
            cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;
    prime_seive(n);
} 
