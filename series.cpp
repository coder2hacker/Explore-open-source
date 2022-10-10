#include<iostream>
using namespace std;

int main(){
    int p;
    cin>>p;
    int count=0;
    int n=0;
    for(n=0;n<=p;n++){
        while(count<p){
            int ele=3*n+5;
            if(ele%5==0){
                continue;
            }else{
                count++;
                cout<<ele;
            }
        }
    }
}