// 12. WAP to take input of base price and display total price of an item.
// (Total price = base price +GST(12%) )

#include <stdio.h>

float gst(float base_price){
    float gst;
    gst = (base_price *12)/100;
    return gst;
}

int main()
{
    float base_price ;
    scanf("%f", &base_price);
    printf("Total Price = %f",base_price + gst(base_price));
    return 0;
}