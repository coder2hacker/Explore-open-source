#include<iostream>
using namespace std;

//Parent Class 1
class Mother
{
	protected:
	/*access region---
			1. inherited class
			2. within the class
			3. friend class
	*/
		int m;
	/*
		m will be shared between the objects of Mother class 
		and the objects of Son class as it is protected.
	*/
	public:
		void display1()
		{
			m=10;
			cout<<"m= "<<m<<endl;
		}
};

//Parent Class 2
class Father
{
	protected:
		int f;
	/*
		f will be shared between the objects of Father class 
		and the objects of Son class as it is protected.
	*/
	public:
		void display2()
		{
			f=12;
			cout<<"f= "<<f<<endl;
		}
};

class Son: public Mother,public Father
{
	/*
		all the inherited possible properties will be
		inherited(from mother and father in the public section of the child class.	
	
	1. Child class data members: m(from mother),f(from father)
	2. Member Functions: 
			a. display1();
			b. display2();
			c. display3();
	*/
	public:
		void display3()
		{
			cout<<"Son"<<endl;
		}
};

int main()
{
	Mother X;
	X.display1();
	
	Father Y;
	Y.display2();
	
	Son S;
	S.display3();
	S.display2();
	S.display1();
	return 0;
}
