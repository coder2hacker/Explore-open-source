#include <iostream>
using namespace std;

											//Operator Overloading

class myclass
{
private:
	int a, b; //data member
public:
	myclass(int x, int y)
	{
		a = x;
		b = y;
	}
	myclass()
	{
		a = 0;
		b = 0;
	}
	void add(myclass passobj1, myclass passobj2)
	{
		a = passobj1.a + passobj2.a; 	//a=10+30=40
		//calling object.a= passObj1.a+passObj2.a
		b = passobj1.b + passobj2.b; 	//b=20+40=60
		//calling object.b= passObj1.b+passObj2.b

	/*
	There is no need of writing the name of the calling object.
	*/
	}
	//using Refference
	void sub(myclass &passobj1, myclass &passobj2)
	{
		a = passobj1.a - passobj2.a;
	//(calling_object)a=passObj1.a-passObj2.a;
		b = passobj1.b - passobj2.b;
	//(calling_object)b=passObj1.b-passObj2.b;
	}
	//using Address
	void sub(myclass *passobj1, myclass *passobj2)
	{
		a = passobj1->a - passobj2->a;
		b = passobj1->b - passobj2->b;
	}
	myclass operator+(myclass);
	void showdata()
	{
		cout << "a = " << a << ", b = " << b << endl;
	}
};

myclass myclass ::operator+(myclass passobj)
{
	myclass temp;
	temp.a = a + passobj.a;
	temp.b = b + passobj.b;
	return temp;
}

int main()
{
	myclass obj1(10, 20);
	/*
	we have created an object of class myclass
	with the help of parametrized constructor
	*/
	myclass obj2(30, 40);
	/*
	we have created another object of class myclass
	with the help of parametrized constructor
	*/
	myclass obj3;
	myclass obj4;
	/*
	we have created two objects obj3 &obj4 of class myclass
	with the help of default constructor
	*/

	obj3.add(obj1, obj2);
	/*
	 	obj3.add(obj1,obj2);
	 	obj3		-->calling object
	 	obj1,obj2	--> passing object
	*/
	cout << "obj3 = obj1 + obj2" << endl;
	obj3.showdata();
	cout << "obj3 = obj1 - obj2" << endl;
	obj3.sub(&obj1, &obj2); //
	/*
	we are passing the address of obj1 and obj2.
	*/
	obj3.showdata();

	obj4.sub(obj1, obj2);
	/*
	we are passing reference of the object.
	*/
	obj4.showdata();

	myclass obj5;
	obj5 = obj1 + obj2; // operator overloading
	
	/*
	int z,x=4,y=3;
	z=x+y;
	
	we are adding y with x and store their result in z.
	_______________________________________________________________________________________________________________
	
	myclass myclass :: operator+ (myclass passObj)
	obj5=obj1+obj2;
	--->obj1+obj2
	we are adding obj2 with obj1 & return back the 
	result to obj5.
	
	obj5.add(obj1,obj2) = obj5=obj1+obj2;---> we are doing same thing...but second one
	is called "Operator Overloading".
	
	myclass operator + (myclass);
	myclass-->return type
	
	step1: obj1+obj2 [here obj1: calling object & obj2: passing object]
	step2: result will be stored to obj5
	
	Goal: obj5 = obj1+obj2
	that means:
	obj5.a = obj1.a+obj2.a
	obj5.b= obj1.b+obj2.b
	
	obj5 = obj1+obj2
	in general '+' operator acts between two operands basically
	they are int,float or double type variable.
	
	+ operator does not work directly in between two
	objects.so, we need to overload + operator.
	
	obj5 = obj1+obj2
	here also obj1	-->calling object
	obj2      		--> passing object
	*/
	obj5.showdata();
	return 0;
}
