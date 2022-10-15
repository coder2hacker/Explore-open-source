#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {   int n,c=0;
        cin>>n;
        int64_t a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];

        sort(a,a+n);
        for(int i=0;i<n-1;i++)
        {
            if(a[i]==a[i+1]) c++;
        }
        if(c==0) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
        
    }
    
 return 0;
}