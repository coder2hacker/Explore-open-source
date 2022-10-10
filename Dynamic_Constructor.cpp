#include<iostream>
#include<string.h>
using namespace std;

//Dyanamic Constructor

class String
{
	//here no access specifier is mentioned,By default it will be private.
	char *name;
	 //Here we want to store string within name;
	int length; //To maintain string length
		
	public:
		/*
		Default constructor*/
	String()  
	{
		//When we are trying to create an object without passing parameters
		length=0;
		name=new char[length+1];
		//name=new char[1];
		/*
		name=""; \0 
		*/	
	}	
	String(char *s)
	{
		//Parameterized constructor
		/*char name[100] for C language
		*/
		length=strlen(s); 
		//we are calculating the length of the string or parameter
		name=new char[length+1]; //+1 for NULL chatacter "\0
		strcpy(name,s);
	}
	void display()
	{
		cout<<name<<"\n";		
	}
	void join(String &a,String &b) 
	{
		length=a.length+b.length;
		delete name;
		
		name=new char[length+1];
		strcpy(name, a.name); //strcpy is used to copy string
		strcat(name, b.name); 
		// strcpy(a,b) b will be copied to a
		// strcat(a,b) it is used to concatenate 2 strings result a=a+b
	}
};
/*
Ritam\0 -->6
Poulami\0 -->8
RitamPoulami\0 -->13
*/
int main()
{
	char *first="Ritam"; //we are declaring a string
	String name1(first); 
	/*
	here we are passing Ritam as parameter 
	for the object name1.ti will evoke 
	the parameterized constructor.
	String(char*s)
	{
		....
	}
	*/
	String name2("Poulami");
	String name3("Paramita");
	
	String s1,s2;
	/*
	It will call default constructor.
	s1.length=0
	s1.name="";
	
	s2.length=0
	s2.name="";
	*/
	s1.join(name1,name2);
	/*
	Approach--->
	strcat(name1,name2);
	Means, name1=name1+name2+\0
	*/
	s2.join(s1,name3);
	
	name1.display();
	name2.display();
	name3.display();
	
	s1.display();
	s2.display();
	
 return 0;
}
