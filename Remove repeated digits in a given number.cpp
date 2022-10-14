
void removerrepeated(ll n)
{
    stack<ll>s;
    s.push(-1);
    ll val;
    while(n)
    {
        val=n%10;
        
        if(val!=s.top())
        {
            s.push(val);
        }
        n=n/10;
    }
    while(s.top()!=-1)
    {
        ll data=s.top();
        cout<<data;
        s.pop();
    }
}
int main()
 {
	//code
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    removerrepeated(n);
	    cout<<endl;
	}
	return 0;
}
