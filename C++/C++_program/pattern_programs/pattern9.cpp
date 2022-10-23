#include<bits/stdc++.h>
using namespace std;

int main(){

    int r;
    cin >> r;
    for( int i = 0; i <= r; i++ ){
        
        for( int j = 0; j <= i; j++ ){
            cout << "* ";
        }
        int gap = 2 * (r - i);
        for( int j = 0; j < gap; j++){
            cout << "  ";
        }
        for( int j = 0; j <= i; j++ ){
            cout << "* ";
        }
        cout << endl;
    }
    for( int i = r - 1; i >= 0; i-- ){
        
        for( int j = 0; j <= i; j++ ){
            cout << "* ";
        }
        int gap = 2 * (r - i);
        for( int j = 0; j < gap; j++){
            cout << "  ";
        }
        for( int j = 0; j <= i; j++ ){
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}