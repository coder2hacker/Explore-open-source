#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int prevmin=-1;
int flag=0;
int x,n,q;

int sorting(int start,int end)
{
    if(start+1==n) {start=0;end=end-n;}
    if(start==end) return arr[start];
    return min(arr[start],sorting(start+1,end));
}

int func(int start,int end)
{
    if(flag==0) {flag++;return prevmin=sorting(start,end);}
    if(arr[start-1]==prevmin) return prevmin;
    return prevmin=(arr[end]<=prevmin)?prevmin:sorting(start,end);

}

int main()
{
    cin>>x>>n;
    int ans=0;
    for(int i=0;i<n;i++)
    {cin>>q;arr.push_back(q);}
    for(int i=0;i<n;i++)
    {
       ans=max(ans,func(i,i+x-1));
    }
    cout<<ans;
}
