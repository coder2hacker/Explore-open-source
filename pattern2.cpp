/* pattern 
*****
*****
*****
*****
*****
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=n;i>0;i--){
        for(int j=0;j<n;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}