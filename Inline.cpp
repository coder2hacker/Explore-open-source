//Inline
#include<iostream>
using namespace std;

inline int Max(int x,int y)  //compiler may accept or may not accept
{
	//it increases the speed of the execution of the code
	//if compiler does not accpet inline request
	return (x>y)?x:y;
}
int main()
{
	cout<<"The result is: "<<Max(20,50)<<endl;
	cout<<"The result is: "<<Max(30,5)<<endl;
	return 0;
}
