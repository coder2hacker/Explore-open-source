#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int amount;
	float balance;
	cin>>amount>>balance;
	if(amount%5==0 && balance>=amount+0.5)
	{
	    cout<<fixed<<setprecision(2)<<(balance-amount-0.5)<<endl;
	}
	else
	cout<<fixed<<setprecision(2)<<balance<<endl;
	return 0;
}
