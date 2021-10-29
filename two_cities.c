// 20. WAP to input distance between two cities in Kilometers. 
// Calculate thedistance in feet, inch and centimeter

#include <stdio.h>

float dist_feet(float dist){
    dist = dist * 3280.84;
    return dist;
}

float dist_inch( float dist){
     dist = dist * 39370.079;
     return dist;
}

float dist_cm( float dist){
    dist = dist * 100000;
    return dist;
}

int main()
{
    float dist ;
    printf("Enter Distance between your two favroite city in KM --->> ");
    scanf("%f", &dist);
    printf(" Distance between your two favroite city in feet --->> %f feets \n", dist_feet(dist));
    printf(" Distance between your two favroite city in inch --->> %f inches \n", dist_inch(dist));
    printf(" Distance between your two favroite city in cm   --->> %f cms \n", dist_cm(dist));
    return 0;
}