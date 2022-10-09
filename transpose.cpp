#include<iostream>
using namespace std;
int main()
{
    int n,m,i,j;
    cout<<"Enter no of rows and colums\n";
    cin>>n>>m;
    int a[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
           cin>>a[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
           cout<<a[j][i]<<" ";
        }
        cout<<endl;
    }

}