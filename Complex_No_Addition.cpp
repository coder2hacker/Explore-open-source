#include<iostream>
#include<math.h>
using namespace std;

class complex
{
	public:
		int real;
		int img;	

	public:
		complex()
		{
			int real=3;
			int img=4;
			cout<<"\nAdd:"<<real<<"+"<<img<<"i";
		}
		complex(int a, int b)
		{
			real = a;
			img = b;
		}
};

int main()
{	
	int real,img;
	complex c;
	complex c1(4,5);
	complex c2(2,3);

	real=c1.real+c2.real;
	img=c1.img+c2.img;
	cout<<"\nadd:"<<real<<"+"<<img<<"i";
return 0;
}
