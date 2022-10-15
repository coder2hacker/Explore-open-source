// rotate an array by d place

#include <iostream>
using namespace std;

int main() {
//code
int T;
cin>>T;
while(T--){
    int N,D;
    cin>>N>>D;
    int Arr[N];
    for(int i=N-D;i<N;i++){
        cin>>Arr[i];
    }
    for(int i=0;i<N-D;i++){
        cin>>Arr[i];
    }
    for(int i=0;i<N;i++){
        cout<<Arr[i]<<" ";
    }
    cout<<endl;
}
return 0;
}
  