#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define F first
#define S second
typedef long long int ll;
const int mod = 1e9+7;

void FAST(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

void fileIO(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

ll query(vector<ll>&st, ll tl, ll tr, ll tv, ll l, ll r){
// completely outside the given range
	if(tl > r || tr < l){
		return 0;
	}
// completely inside the given range
	if(tl >= l && tr <= r){
		return st[tv];
	}
// Partially inside and partially outside
	ll tm = (tl+tr)/2;
	ll ans1 = query(st, tl, tm, 2*tv, l, r);
	ll ans2 = query(st, tm+1, tr, 2*tv+1, l, r);
	return ans1 +ans2;
}

void updateTree(vector<ll>&arr, vector<ll>&st, ll tl, ll tr, ll tv, ll idx, ll value){
	if(tl==tr){
		arr[idx] = value;
		st[tv] = arr[idx];
		return;
	}
	ll tm = (tl+tr)/2;
	if(idx > tm){
		updateTree(arr, st, tm+1, tr, 2*tv+1, idx, value);
	} else {
		updateTree(arr, st, tl, tm, 2*tv, idx, value);
	}
	st[tv] = st[2*tv]+st[2*tv+1];
}

void buildTree(vector<ll>&arr, vector<ll>&st, ll tl, ll tr, ll tv){
// BASE CASE
	if(tl == tr){
		st[tv] = arr[tl];
		return;
	}

	ll tm =(tl+tr)/2;
	// two recursive calls to build the left half and
	// right half respectively
	buildTree(arr, st, tl, tm, 2*tv);
	buildTree(arr, st, tm+1, tr, 2*tv+1);
	// the answer to the recursive calls gets stored in
	// the tv
	st[tv] = st[2*tv]+st[2*tv + 1];
}



int main(){
	FAST();
	fileIO();
	ll n,q,x, a,b,k,u,qt;
	cin>>n>>q;
	vector<ll> arr(n);
	vector<ll> st(4*n);
	for(ll i=0 ; i<n ; i++){
		cin>>arr[i];
	}

	buildTree(arr, st, 0,n-1,1);

	for(ll i=0 ; i<q ; i++){
		cin>>qt;
		if(qt==1){
			cin>>k>>u;
			updateTree(arr, st, 0, n-1, 1, k-1, u);
		}
		if(qt==2){
			cin>>a>>b;
			cout<<query(st, 0, n-1, 1, a-1, b-1)<<"\n";
		}
	}
	return 0;
}
