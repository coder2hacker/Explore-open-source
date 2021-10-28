#include<iostream>
using namespace std;
long long unsigned gcd(long long unsigned a, long long unsigned b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do
    {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}
int main(void)  {
    long long unsigned a,b;
    cout<<"Enter two numbers :";
    cin>>a>>b;
    cout<<"GCD of "<<a<<" "<<b<<" is "<<gcd(a,b)<<endl;
    return 0;
}