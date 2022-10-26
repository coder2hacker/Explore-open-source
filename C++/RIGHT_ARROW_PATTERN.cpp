#include <iostream>
using namespace std;
int main()
{
int i, j, n;
cin >> n; 
int num = n / 2 * 3;

cout << "Right Arrow" << endl;
for(i = 0; i < n; i++)
{
for(j = 0; j < n; j++)
{

if(i == n / 2 || j - i == n / 2 || i + j == num)
cout << "*";
else
cout << " ";
}
cout << endl;
}

return 0;
}
