#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int a[s.length() / 2 + 1],i;
    for ( i = 0; i < s.length(); i++)
        if (i % 2 == 0)  a[i / 2] = (s[i]) - 48;
    
  
        sort(a,a+(s.length()/2+1));
        for ( i = 0; i < s.length()/2; i++)
           {cout<<a[i]<<'+';
            
           }
           cout<<a[i];
    return 0;
}