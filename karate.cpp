#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,s1,s2,s3,s4;
	    cin>>n>>s1>>s2>>s3>>s4;
	    if(s1>=s2){
	        cout<<0<<endl;continue;
	    }
	    if(s3<=0){
	        cout<<"FAIL"<<endl;continue;
	    }
	    int ans=0;
	    int count=1;
	    while(s1<s2 && ans<n){
	        s1+=s3;
	        count++;
	        ans++;
	        if(count==5){
	            s1-s4;count=1;
	        }
	    }
	    if(ans==n && s2 > s1){
	            cout<<"FAIL"<<endl;
	        }
	        else{
	            cout<<ans<<endl;
	        }
	}
	return 0;
}