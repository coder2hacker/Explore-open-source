#include<bits/stdc++.h>
using namespace std;
int build_segment_tree(int arr[],int start,int end,int *st,int index)
{
    if(start==end)
    {
        st[index]=arr[start];
        return arr[start];
    }
    int mid=(start+end)/2;
    st[index]=min(build_segment_tree(arr,start,mid,st,2*index+1),build_segment_tree(arr,mid+1,end,st,2*index+2));
    return st[index];
}
int* construct_seg_tree(int arr[],int n)
{
    int height=(int)(ceil(log2(n)));
    int max_length=2*(int)pow(2,height)-1;
    int* segtree=new int[max_length];
    build_segment_tree(arr,0,n-1,segtree,0);
    return segtree;
}
int range_query_min(int* st,int start,int end, int l,int r,int index)
{
    if(l>=start&&r<=end)//total overlap
    {
        return st[index];
    }
    else if(l>end||r<start)
    {
        return INT_MAX;
    }
    else
    {
        int mid=(start+end)/2;
        return min(range_query_min(st,start,mid,l,r,2*index+1),range_query_min(st,mid+1,end,l,r,2*index+2));
    }
}
int range_query(int *st,int start,int end,int l,int r,int index)
{
    if(l<0||r>end-1||l>r)
    {
        cout<<"Enter a valid range"<<endl;
        return -1;
    }
    return range_query_min(st,0,end-1,l,r,0);
}
int main()
{
    int n;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int *segment=construct_seg_tree(arr,n);
    cout<<"enter the query range"<<endl;
    int l,r;
    cin>>l>>r;
    cout<<range_query(segment,0,n,l,r,0);
    return 0;
}