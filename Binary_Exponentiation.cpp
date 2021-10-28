#include<iostream> 
using namespace std;
long long unsigned binpow(long long unsigned a, long long unsigned b)
{
    long long unsigned res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}
int main(void) {
    int base,expo;
    cout<<"Enter the base & expo: ";
    cin>>base>>expo;
    cout<<"The result of "<<base<<"^"<<expo<<" is "<<binpow(base,expo)<<endl;
    return 0;
}