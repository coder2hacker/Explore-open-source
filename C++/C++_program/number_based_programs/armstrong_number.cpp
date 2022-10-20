#include <iostream>
using namespace std;

int main () {
    int num, originalNum, remainder, result=0;
    cout << "Enter a three-digit number ";
    cin >> num;
    originalNum = num;

    while ( originalNum != 0 )
     {
        remainder = originalNum % 10;

        result += remainder * remainder * remainder;

        originalNum /= 10;
    }
    if ( result == num )
    cout << num << "is an Armstrong Number ";
    else
    cout << num << "is not an Armstrong Number ";
    return 0;
}