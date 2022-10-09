#include<iostream>
using namespace std;

class A
{
	private:
		int A=10;
	public:
		void displayA()
		{
			cout << "Display A" <<endl;
			cout << "A= " <<A << endl;
		}
};

class B : public A
{
	private:
		int B=20;
	public:
		void displayB()
		{
			cout << "Display B" <<endl;
			cout <<"B= " << B << endl;
		}
};

class C : public A
{
	private:
		int C=30;
	public:
		void displayC()
		{
			cout << "Display C" <<endl;
			cout << "C= "<< C << endl;
		}
};

class D : public B , public C
{
	private:
		int D=40;
	public:
		void displayD()
		{
			cout<< "Display D" <<endl;
			cout << "D= "<< D << endl;
		}
};

int main()
{
	A Obj1;
	Obj1.displayA();
	
	B Obj2;
	Obj2.displayB();
	Obj2.displayA();
	
	C Obj3;
	Obj3.displayC();
	Obj3.displayA();
	
	D Obj4;
	Obj4.displayD();
	Obj4.displayB();
	Obj4.displayC();
	// Obj4.DisplayA(); ---> Diamond Problem (Ambiguious)
	/*
	What is Diamond Problem?
		In case of hybrid inheritance if there is a scenario like 
		that 
			if there is a parent(class A) and that parent has 2 children(class B,C) and again 
			2 children are the parent of another class(Class D),then
			Diamond Problem Occurs.  
		
	*/
	
	return 0;
}
