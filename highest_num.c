// 9. Find the highest number in the given 4 numbers

#include <stdio.h>

int highest_num(int num1, int num2, int num3, int num4){
    int highest_num;
    if(num1 > num2){
        if(num1 > num3){
            if(num1 > num4){
                highest_num = num1;
            }else{
                highest_num = num4;
        }
    }
}
else if (num2 > num3)
{
    if(num2 > num4){
        highest_num = num2;
    }else{
        highest_num = num4;
    }
}
else if (num3 > num4)
{
    highest_num = num3;
}else{
        highest_num = num4;
    }

    return highest_num;
}


int main()
{
    int num1, num2, num3, num4;
    printf("Enter four numbers\n");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
    printf("Highest number in %d %d %d %d is %d", num1 , num2, num3, num4, highest_num(num1 , num2, num3, num4));


}