#include <iostream>
using namespace std;

int check ( int n )
{
    int r = 0, sum = 0;
    while ( n > 0 ) {
        r = n % 10;
        sum = sum + ( r * r );
        n = n / 10;
    }
    return sum;
}

void solve ( int n ) 
{
    int new_n = n;
    while ( new_n != 1 && new_n != 4 ) {
        new_n = check ( new_n );
    }
    if ( new_n == 1 )
    cout << n << "is a happy number ";
    else
    if ( new_n == 4 )
    cout << n << "is not a happy number ";
}

int main ()
{
    int n;
    cout << "Enter the number ";
    cin >> n;
    solve ( n );
    return 0;
}