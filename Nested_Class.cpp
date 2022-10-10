//One nested class within an outer class
#include<iostream>
using namespace std;

class A
{
    public:
    class B
    {
        private:
        int n=90;

        public:
        void display()
        {
            cout<<"The result is: "<<n;
        }
    };
};
int main()
{
    A::B obj;
    obj.display();
    return 0;
}