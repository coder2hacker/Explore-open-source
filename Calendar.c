#include <stdio.h>
#include <stdlib.h>
void print_1_line();
int mday(int i);
int get_strt_day(int y);
void month_name(int i);

int main()
{
    int y,sday,j,k,flag,count,i;
    //sday=0-sunday, 1-monday....
    printf("enter year\n");
    scanf("%d",&y);
    sday = get_strt_day(y);
    //printf("%d\n", sday);
    for (i=1;i<=12;i++)
        {month_name(i); //prints month name
        print_1_line(); //days
        //first row
        for (k=0; k<sday;k++) printf("    "); //for the spaces in first day of week
        count=1;
        while (k<7){
            printf("%2d  ",count);
            count++;
            k++;}
        //First row end
        printf("\n");
        flag=0;
        for (j=1;j<6;j++) //the pattern
        {for(k=0;k<7;k++)
          {printf("%2d  ",count);
           count++;
           if (count > mday(i)) //last date
            {sday=k+1;
            flag=1;
            printf("\n");
            break;
           }
        }
        if (flag==1) break;
        printf("\n");
        }
        }
    return 0;
}
int get_strt_day(int y)
{
    int t;
    t=365*y+y/4+y/400-y/100;
    t%=7;
    return t;

}
void print_1_line()
{
   printf("\nsun mon tue wed thur fri sat\n");
}
int mday(int i)
{
    if ( i==2 ) {if ( i%400==0 || (i%4==0 && i%100!=0))
                     return 29;
                 else return 28;}
    else if( i==4 || i==6 || i==9 || i==11)
         return 30;
    else return 31;

}
void month_name(int i)
{
    printf("\n----------------------------\n");
    switch (i)
    {
        case 1: printf("            january"); break;
        case 2: printf("           February"); break;
        case 3: printf("             March"); break;
        case 4: printf("             April"); break;
        case 5: printf("             May"); break;
        case 6: printf("            June"); break;
        case 7: printf("            july"); break;
        case 8: printf("             August"); break;
        case 9: printf("          September"); break;
        case 10: printf("           October"); break;
        case 11: printf("          November"); break;
        case 12: printf("          December"); break;
            }
}
