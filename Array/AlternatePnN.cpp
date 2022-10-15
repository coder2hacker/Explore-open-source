using namespace std;
#include <iostream> 
#include <vector>

void rearrange(int arr[], int n){
    vector <int> pos;
    vector <int> neg;
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    int posindex=0;
    int negindex=0;
    for(int i=0;i<n;i++){
        if(posindex<pos.size() && posindex==negindex){
            arr[i]=pos[posindex];
            posindex++;
        }
        else if(negindex<neg.size() && posindex>negindex){
            arr[i]=neg[negindex];
            negindex++;
        }
        else if(negindex==neg.size() && posindex<pos.size()){
            arr[i]=pos[posindex];
            posindex++;
        }
        else if(posindex==pos.size() && negindex<neg.size()){
            arr[i]=neg[negindex];
            negindex++;
        }
    }
}

int main(){
    int arr[9] = {9, 4, -2, -1, 5, 0, -5, -3, 2};
    rearrange(arr,9);
    for (int i = 0; i < 9; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}