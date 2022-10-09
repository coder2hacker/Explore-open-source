#include<iostream>
using namespace std;
int main()
{
    int n, count;
    cout<<" ENter the lenght of silver bar :";
    cin>>n;
    cout<<"\n Min cut required is : ";
    while(n!=0){
        count = 0;
        while(n>1){
            n=n/2;
            count++;  
        }
        cout<<count;
        if(n==1) break;
    }
    return 0;
} 

//==================================== OR ==========================================

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        int n;
        cout<<"Enter the silver bar length :";
        cin>>n;
        cout<<" Min cut is  :"<< (int)(log2(n));
        break;
    }
    return 0;

}