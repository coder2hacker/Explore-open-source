#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct point{
        int x, y;
    };
    bool mycomp(point p1, point p2){  //iska use krke humne khuda order define kiya h
        return(p1.x < p2.x);            //iss case m humne decide kiya h ki x ki value ke hisaab se sort hoga
    }

int main() {
	int arr[5] = {2,9,6,4,3};
    sort(arr, arr+5); // default soting from min to max
    sort(arr, arr+5, greater<int>()); // greater<int>() specifies the order in which the array is sorted
    for(int i : arr){
        cout<<i<<" ";
    } 

    vector<int> v = {4,2,8,5,9};
    sort(v.begin(), v.end());
    sort(v.begin(), v.end(), greater<int>());
    for(int i : arr){
        cout<<i<<" ";
    } 

    point arr[3] = {{3,10}, {2,8}, {5,4}};
	sort(arr,arr+3,mycomp);
	
	//for(auto i: arr)
	  //  cout<<i.x<<" "<<i.y<<endl;
}