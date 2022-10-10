#include <bits/stdc++.h>
using namespace std;

void prime_seive(int n)
{
    int i,j;
    vector<int> seive(n);
    for(i=2;i*i<=n;i++)
    {
        if(seive[i]==0)
        {
            for(j=i*i;j<=n;j+=i)
            {
                seive[j]=1;
            }
        }
    }
    for(i=2;i<=n;i++){
        if(seive[i]==0)
        cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin>>n;
    cout<<"Hello"<<endl;
    prime_seive(n);
    // prime_factors(n);
}