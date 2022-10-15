#include<bits/stdc++.h>
using namespace std;
queue<long long int> rev(queue<long long int> q);
int main()
{
    long long int test;
    cin>>test; 
    while(test--)
    {
    queue<long long int> q; 
    long long int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<long long int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}// } Driver Code Ends


//function Template for C++

queue<long long int> rev(queue<long long int> q)
{
    // add code here.
    stack <long long int> s;
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        long long int data=s.top();
        q.push(data);
        s.pop();
    }
    return q;
}
