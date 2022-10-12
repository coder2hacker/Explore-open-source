#include<stdio.h>
#include<math.h>

int sqr()
{
    float s, area;
        printf("Enter the side of the square : ");
        scanf("%f", &s);
        area= s*s;
        printf("Area of square = %f",area);
        return(area);
}

int rct()
{
   float l,b,area;
        printf("Enter the length & breadth of rectangle :\n");
        scanf("%f %f", &l, &b);
        area= l*b;
        printf("Area of rectangle = %f",area);
        return(area);
}

int trg()
{ 
    float a, b, c, s, area;
        printf("Enter the length of three sides of triangle :\n");
        scanf("%f  %f  %f", &a, &b, &c);
        s=(a+b+c)/2;
        area= sqrt(s*(s-a)*(s-b)*(s-c));
        printf("Area of triangle = %f", area);
        return(area);
}

int cir()
{
  float r, area, pi=3.14;
        printf("Enter the radius of circle : ");
        scanf("%f",&r);
        area= pi*r*r;
        printf("Area of circle = %f",area);
        return(area);
}
int main()
{   
    int choice;
    printf("Enter 1 if you want to calculate are of square\nEnter 2 if you want to calculate are of rectangle\nEnter 3 if you want to calculate are of triangle\nEnter 4 if you want to calculate are of circle\n ");
    scanf("%d", &choice);
    switch(choice)
    {   
        case 1 :
        sqr();
        break;
        
        case 2 :
        rct();
        break;
        
        case 3 :
        trg();
        break;
        
        case 4 :
        cir();
        break;
        
        default:
        printf("INVALID CHOICE!!");
        
    }
    return 0;

}
