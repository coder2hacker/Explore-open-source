#include<bits/stdc++.h>
using namespace std;
int main()
{   long long n,k; //1,3,5,7, 2,4,6,8
    cin>>n>>k;
    if(n%2==0)
{    if(k<(n/2+1)) cout<<2*k-1;
    else cout<<2*(k-(n/2));}
    if(n%2!=0)
{    if(k<=(n/2+1)) cout<<2*k-1;
    else cout<<2*(k-(n/2+1));}


 return 0;
}