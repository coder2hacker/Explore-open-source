#include<iostream>
using namespace std;

class ABC
{
    int i;
    mutable int j; //Mutable  is a keyword & j is mutable,private,non constant dada member
/*
    The keyword mutable is mainly used to allow a particular data 
    member of constant object to be modified.
    Adding mutable top a variable allows a const pointer to change members.
    mutable is particularly userful if most of the members should be constant but a 
    few need to be updateable.
    Data members declared as mutable can be modified even though they are the part of
    object declared as const. 
    U can't used mutable specifier with next declared as static or const or reference.
 */
    public:
        ABC()
        {
            i=0;
            j=0;
        }
        void f() const
        {
            j++;
        /*
            Within constant method we can't update non constant data member.
            for that reason we need mutable.
        */
            cout<<"\n The value of j= "<<j;
        }
};

int main()
{
    const ABC obj;
    obj.f();
    return 0;
}
