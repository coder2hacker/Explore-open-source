#include <iostream>
using namespace std;

int main() {
 
  int size = 5;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i==j || i+j==size-1) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout <<endl;
  }
  return 0;
}
