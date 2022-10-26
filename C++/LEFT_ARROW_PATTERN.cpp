#include <iostream>
using namespace std;
int main()
{
int i, j, n;
cin >> n;
int num = n / 2 * 3;

cout << "Left Arrow" << endl;
for(i = 0; i < n; i++)
{
for(j = 0; j < n; j++)
{

if(i == n / 2 || i - j == n / 2 || i + j == n / 2)
cout << "*";
else
cout << " ";
}
cout << "\n";
}
return 0;
}
