#include<iostream>
using namespace std;

class myclass
{
	private: //Access specifier
		int num; // num is private here
	public:
		//public section
		void get_data() 
		{
			cout<<"\nEnter a number: ";
			cin>>num;
		}
		//set_data 3 times definition with different parameter-->method overloading list
		void set_data(myclass passob) //copy means value
		{
			num=passob.num;
			/*
				calling object.num=passob.num
				ob1.num=ob2.num
				As passob(formal parameter) = ob2 (actual parameter)
				
				for calling object we don't need to write the object 
				name to access properly within the method.
			*/
		}
		void set_data(int a, myclass &passob) //call by reference
		{
			num=passob.num; 
			/*
				calling object.num=passob.num
				ob4.num=ob2.num
				As passob(formal parameter) = ob2 (actual parameter)
				
				for calling object we don't need to write the object 
				name to access properly within the method.
			*/
		}
		void set_data(myclass *passob) //call by address
		{
			num=passob->num;
			/*
				calling object.num=passob->num
				ob3.num=ob2.num
				As passob(formal parameter) = ob2 (actual parameter)
				
				for calling object we don't need to write the object 
				name to access properly within the method.
			*/
		}
		void show_data()
		{
			cout<<"\nNum= "<<num;
		}
						
};

int main()
{
	//we are declaring 4 objects of the class myclass
	myclass ob1,ob2,ob3,ob4;
	int a=0;
	ob2.get_data();
	//ob2.num=user_value
	
	ob1.set_data(ob2); //copy means value
	/*
	we are trying to set the value of ob1.num by 
	the value of ob2.num.
	
	calling object= ob1
	passing object= ob2
	
	here we are passing an object ob2 within an object method ob1.set_data(..)
	what is the data type of ob2?
		it's defiend as myclass ob2;
		so, data type of ob2 is user defined data 
		type that is my class.
	
	Function calling line
		function_name(actual_parameter);
	Funtion definition line
		return_type funtion_name(data_type formal_parameter);
		{
			....
		}
	Target of ob1.set_data(ob2);
		Target is to setup ob1.num=ob2.num
		
	-------------------------------------------------
	
	for object ob1--->
	ob1.num
	ob1.get_data
	ob1.set_data
	ob1.set_data
	ob1.set_data
	ob1.show_data
	
	---------------------------------------------------
	*/
	
	ob3.set_data(&ob2); //address-->we are passing address of ob2
	ob4.set_data(a,ob2); //reference
	
	ob1.show_data();
	ob2.show_data();
	ob3.show_data();
	ob4.show_data();
	
	return 0;
}
/*
	int a
	int is system defined data type
	
	myclass myobj;
	myclass is a user defined data type
	myobj is an object here

*/
