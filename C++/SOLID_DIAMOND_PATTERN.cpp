#include <iostream>
using namespace std; 
int main()
{
    int i, j, n;
    cin >> n;
   
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < (2 * n); j++)
        {
            if(i + j <= n - 1)   
                cout << "*";
            else
                cout << " ";
            if((i + n) <= j)  
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
 
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < (2 * n); j++)
        {
            if(i >= j)  
                cout << "*";
            else
                cout << " ";
            if(i >= (2 * n - 1) - j)  
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
