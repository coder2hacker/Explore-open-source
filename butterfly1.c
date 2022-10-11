#include<stdio.h>
int main(){
    int n=5,i,j,k;
    int space=n-1,star=1;
    for(i=1;i<=n*2;i++){
        for(j=1;j<=star;j++){
            printf("* ");
        }
        for(j=1;j<=space*2;j++){
            printf("  ");
        }
        for(j=1;j<=star;j++){
            printf("* ");
        }
        if(i<n){
            star++;
            space--;
        }else{
            space++;
            star--;
        }
        printf("\n");
    }
    return 0;

}