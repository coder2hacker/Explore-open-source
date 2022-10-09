//This Pointer
#include<iostream>
using namespace std;
class First
{
	private:
		int a; // here a is data member
	public:
		void access(int a) //here a is formal parameter
		{
			this->a=a;
			/*
			this->data member of the class= formal parameter
				our target is to set data member(a) with the value of 
				formal parameter(a).
			To distingush the both a using this.
				this pointer is to determine the properties of the
				current object.
			*/
		}
		void display()
		{
			cout<<"a= "<<a<<endl;
			// cout<<"a= "<<this->a<<endl;
		}
};

int main()
{
	First F;
	F.access(10);
	F.display();
	return 0;
}
