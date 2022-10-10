// Empty Class

#include <iostream>
using namespace std;
class Empty
{

};

int main()
{
    Empty e;
    cout<<"size of Empty class= "<<sizeof(Empty)<<endl;
    cout<<"size of Empty class= "<<sizeof(e)<<endl;
    cout<<"Address of Empty class's object= "<<hex<<&e;
    return 0;
}