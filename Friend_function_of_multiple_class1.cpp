
//Friend Function of multiple class
#include<iostream>
using namespace std;
class Second;

/*
	Prorotype Declaration---->class Second;
	Reason:
		because we are using a friend funtion of multiple class,
		so,when we going to declare compare function as friend of First & 
		Second,then at the time of declaration within First class still
		class Second is not defined,So,if we don't write prototype 
		declaration the compiler will not identify what is "Second".
	
*/

class First
{
	private:
		int a;
	public:
		void take_val();
		void display();
		friend void compare(First,Second);
};

void First :: take_val()
{
	cout<<"Enter value for a:\n";
	cin>>a;
}
void First :: display()
{
	cout<<"a= "<<a<<endl;
}

class Second
{
	private:
		int b;
	public:
		void take_val2();
		void display2();
		friend void compare(First,Second);
};

void Second::take_val2()
{
	cout<<"Enter the value for b:\n";
	cin>>b;
}
void Second :: display2()
{
	cout<<"b= "<<b<<endl;
}


void compare(First F,Second S)
{
		
	if(F.a>S.b)
		cout<<"max:"<<F.a;
	else
		cout<<"Max:"<<S.b;
	
}

int main()
{
	First F1;		
	F1.take_val();
	F1.display();
	
	Second S1;
	S1.take_val2();
	S1.display2();
	
	compare(F1,S1);	
	return 0;
}

