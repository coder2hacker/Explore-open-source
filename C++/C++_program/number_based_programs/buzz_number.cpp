#include <iostream>
using namespace std;

int main ()
{
    int n;
    cout << "Please enter a number ";
    cin >> n;
    if ( n % 7 == 0 || n % 10 == 7 )
    cout << n << "is a buzz number " << endl;
    else 
    cout << n << "is not a buzz number " << endl;
    return 0;
}