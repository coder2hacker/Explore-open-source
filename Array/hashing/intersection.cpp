using namespace std;
#include <iostream> 
#include <unordered_set>

int intersection(int a[], int m, int b[], int n){
    int z = 0;
    unordered_set<int> set(a, a+m);  
    for (int i = 0; i < n; i++)
    {
        if(set.find(b[i]) != set.end()){
            z++;
            set.erase(b[i]);
        }
    }
  return z;  
}

int main(){
    int a[] = {5,10,15,5,10}, b[] = {15,5,5,10,4};
    cout<<intersection(a,5,b,5);
}