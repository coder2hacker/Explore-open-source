#include<stdio.h>

float area(int r);

int main(){

    float r, circle_area;

    printf("\n  Enter The Radius: ");
    scanf("%d", &r);

    circle_area = area(r);

    printf("\n Area Of Circle = %d", circle_area);



return 0;

}

float area(int r){

    float area1 = (22*r*r)/7;

    return area1;
}
