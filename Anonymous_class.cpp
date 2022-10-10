// Anonymous Class {Type 1}

#include <iostream>
using namespace std;

typedef class
/*here the name of the class is missing so we can call it 
nameless class or anonymous class*/
{
    private:
    int x;

    public:
    void get_data()
    {
        cout<<"\nEnter the value of x: ";
        cin>>x;
    }
    void show_data()
    {
        cout<<"\nx="<<x;
    }
}Number;


int main()
{
    Number N1;
    /*here N1 is object of a nameless class.
        Number is used as an alternative name for the nameless class is achived by
        typedef. typedef is used to rename the data type name.
        here we have defined a class using typedef class. No class name is present here,
        but at the end of the class declaration we have renamed the nameless class.
    */
    N1.get_data();
    N1.show_data();
    return 0;
}