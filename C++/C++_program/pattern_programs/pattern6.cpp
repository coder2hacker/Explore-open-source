#include <iostream>
using namespace std;

int main ()
{
    int rows;
    cout << "Enter number of rows ";
    cin >> rows;
    for ( int i = 1; i <= rows; i++ )
    {
        char first = 'A';
        char last = first + rows - i;
        char c = 'A';
        int cols = rows - i + 1;
        for ( int j = 1; j <= cols; j++ )
        {
            cout << c << " ";
            c += 1;
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}