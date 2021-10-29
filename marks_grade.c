// 13. WAP to take input of 5 subject marks and display the grade according to table:
#include <stdio.h>

int grade(int sub1 , int sub2, int sub3, int sub4, int sub5){
    int avgMarks;
    avgMarks = (sub1 + sub2 + sub3 + sub4  + sub5) / 5;
    if(avgMarks >= 90){
        printf("Your Grade according to your Average Marks  is A+ ");
    }
    else if (80 <= avgMarks  &&  avgMarks < 90 )
    {
        printf("Your Grade according to your Average Marks  is A  %d" , avgMarks);

    }else if (70 <= avgMarks &&  avgMarks < 80 )
    {
        printf("Your Grade according to your Average Marks  is B+ ");
    }else if (60 <= avgMarks &&  avgMarks < 70 )
    {
        printf("Your Grade according to your Average Marks  is B ");
        
    }else if (50 <= avgMarks &&  avgMarks < 60 )
    {
        printf("Your Grade according to your Average Marks  is C ");
    }else{
        printf(" Sorry! you are failed in the examination ");
    }
    
    return 0;
}

int main()
{
    int sub1,sub2,sub3,sub4,sub5 ;
    printf("Enter marks obtain in 5 subject \n");
    scanf("%d%d%d%d%d", &sub1,&sub2,&sub3,&sub4,&sub5);
    grade(sub1,sub2,sub3,sub4,sub5);
    return 0;
}