/*Write a program in c++ that has a class Triangle and data members side1,side2 and side3.
//One method calarea() 
Use default constructor
Parametrized constructor and copy constructor
*/

#include<iostream>
#include<math.h>
using namespace std;

class Triangle
{
	private:
		float side1,side2,side3;
		float area;
	
	public:
		Triangle()
		{
			side1=6;
			side2=6;
			side3=6;
		}
		
		Triangle(float a,float b,float c)
		{
			area=0;
			side1=a;
			side2=b;
			side3=c;
		}
		Triangle(Triangle &s)
		{
			side1=s.side1;
			side2=s.side2;
			side3=s.side3;
		}
		void calarea()
		{
			float s;
			if(((side1+side2)>side3)||((side1+side3)>side2))
			{
				s=(float)(side1+side2+side3)/2;
				area=(float)sqrt(s*(s-side1)*(s-side2)*(s-side3));
			}
			else
			{
				cout<<"\nTriangle is not valid";
			}
			
			//cout<<area;
			
		}
		void display()
		{
			cout<<"\narea of the triangle:"<<area;
		}
		
};

int main()
{
	Triangle s1;
	s1.calarea();
	s1.display();
	
	Triangle s2(20,25,30);
	s2.calarea();
	s2.display();
	
	Triangle s3(s2);
	s3.calarea();
	s3.display();
	
	return 0;
}

