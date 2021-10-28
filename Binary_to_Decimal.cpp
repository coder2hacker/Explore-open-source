#include <iostream>
using namespace std;
long long unsigned bintodec(string s)
{
    long long unsigned ans = 0, d = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        ans += (s[i] - '0') * d;
        d *= 2;
    }
    return ans;
}
int main(void)
{
    string binary;
    cout << "Enter a binary number: ";
    cin >> binary;
    cout << "The decimal representation of binary number " << binary << " is " << bintodec(binary) << endl;
    return 0;
}