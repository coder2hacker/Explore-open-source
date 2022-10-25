//inserting an element in array using vector
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
  vector<int> v;
  int i,ie,n,p;
  cout<<"size of array"<<endl;
  cin>>n;
  for(i=0;i<n;i++)
  {
    v.push_back(i);
  }
  for(i=0;i<n;i++)
  {
    cout<<v[i]<<" ";
  }
  cout<<"enter which no element you want to insert"<<endl;
  cin>>ie;
  cout<<"enter index where you want to enter the element"<<endl;
  cin>>p;
  auto it=v.begin()+p;
  auto iter=v.insert(it,ie);
  for(i=0;i<n;i++)
  {
    cout<<v[i]<<" ";
  }
}
