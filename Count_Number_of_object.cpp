//count the number of the objects in this program
#include<iostream>
using namespace std;

class myclass
{
	private:
		int a=8,b=9;
	public:
	myclass()
	{
		a=8;
		b=9;
		count++;
	}
	
	myclass(int x,int y)
	{
		a=x;
		b=y;
		count++;
	}
	static int count;
	void display()
	{
		cout<<"\na= "<<a<<"\nb= "<<b<<endl;
	}
	static void count1()
	{
		cout<<"No of objects= "<<count<<endl;	
	}	
};

int myclass::count=0;
int main()
{
	cout<<"\nFor object1--->";
	myclass s1; //creating object s1 with default constructor
	s1.display(); //a=8 b=9
	s1.count1();  //count=0;---> count++;---> count=1
	
	cout<<"\nFor object2--->";
	myclass s2(20,60); //creating object s2 with parameterized constructor
	s2.display(); // a=20 b=60
	s2.count1(); //count=1--->count++ ---> count=2
	
	cout<<"\nFor object3--->";
	myclass s3; //creating object s3 with default constructor
	s3.display(); //a=8 b=9
	s3.count1(); //count=2--->count++ ---> count=3
	
	
	return 0;
}

