
#include <iostream>
using namespace std;
 
int linearSearch(int array [], int size, int key) {
    
    for (int i = 0; i<size; i++ ) {
        if (array [i] == key) {
            return 1;
        }
    }
    return 0;
 }

int main() {

    int arr [10] = {5, 7, -2, 10, 22, -2, 0, 5, 22, 1};

    cout << "Enter the element to be searched " << endl;
    int key;
    cin >> key;

    bool found = linearSearch (arr, 10, key);

    if (found) {
        cout << "Key is present " << endl;
    }
    else  {
        cout << "Key is absent " << endl;
    }
    
return 0;
}