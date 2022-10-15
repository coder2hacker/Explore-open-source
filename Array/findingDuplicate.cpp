using namespace std;
#include <iostream>
#include <vector> 

vector<int> duplicate(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        arr[arr[i]%n] += n;
    }
    for (int i = 0; i < n; i++)
    {
        
    }
    
}

int main(){
 
}