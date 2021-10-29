/* 19. WAP to calculate and print the Electricity bill of a given customer. 
The customer id and unit consumed by the customer should be taken from the 
keyboard and display the total amount to pay to the customer. 
The charge are as follow :
Unit Cunsumption Charge/Unit
upto 199 @4.20
200 and above but less than 400 @5.50
400 and above but less than 600 @6.80
600 and above @8.00
If bill amount exceeds Rs. 800 then a surcharge of 18% will be charged and the 
minimum bill should be of Rs. 200.
*/

float bill(int units){
    float bill = 0;
    if(units < 200){
        bill = 4.20 * units ;
    }else if(200 <= units && units < 400){
        bill = 5.50 * units;
    }else if(400 <= units && units < 600){
        bill = 6.80 * units;
    }else if(600 <= units ){
        bill = 8.00 * units;
    }

    if(bill > 800){
        bill += (bill * 18) / 100 ;
    }
    else if(bill < 200){
        bill = 200;
    }
return bill;

}
#include <stdio.h>
int main(){
    int c_id , units ;
    printf("*************************** Welcome to Abhi's E-bill Calculator*************************\n");
    printf("Enter your Coustomer Id : ");
    scanf("%d", &c_id);
    printf("How much unit of Electricity you consume this month : ");
    scanf("%d", &units);
    printf(" Total Electricity bill of %d is Rs. %.2f" , c_id , bill(units));

}