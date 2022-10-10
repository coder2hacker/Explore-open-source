#include<iostream>
#include<string.h>
using namespace std;
//Destructor

class Sample
{
	private:
		int x;
	
	public:
		Sample()
		{
			x=2;
			cout<<"\nDefault Constructor Called";
		}
		Sample(int a)
		{
			x=a;
			cout<<"\n2.Parametrized Constructor Called"<<x;
		}
		Sample(int b,int y)
		{
			x=b;
			cout<<"\n@Parametrized Constructor Called"<<x;
		}
		
		/*
		What is destructor?
		1. Destructor also a special member function that is 
		used to deallocate memeory.
		2. It is also envoked  automatically when the objects are going
		out of the scope.
		3. ~classname()
		4. No parameter are passed.
		5. Destructor can't be overloaded.
		6. ~ Tilde operator.
		7. Class name & Destructor name also be same.
		*/
		~Sample()
		{
			cout<<"\nDestructor Called";
			cout<<"X="<<x;
		}
		
};

int main()
{
	
	Sample s1;
	Sample s2(12);
	Sample s3(15);
	//j order e constructor calling hy tar opposite order e destructor calling hy 
	/*
	Ex-->
	Destructor CalledX=15
	Destructor CalledX=12
	Destructor CalledX=2
	*/
	return 0;
}
