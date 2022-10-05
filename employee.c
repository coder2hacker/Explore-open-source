#include<stdio.h>
#include<conio.h>
struct dob
{
	int d,m,y;
	
};
struct employee
{
	char name[20];
	int age;
	struct dob d1;
};
struct student
{
	char name[20];
	int age;
	struct dob d2;
};
void main()
{
	
	struct student stu1;
	struct employee emp1;
	scanf("%s%d",stu1.name,&stu1.age);
	scanf("%s%d",emp1.name,&emp1.age);
	display(stu1,emp1);
}
void display(struct student s,struct employee e)
{
	printf("%s%d",s.name,s.age);
	printf("%s%d",e.name,e.age);
}
