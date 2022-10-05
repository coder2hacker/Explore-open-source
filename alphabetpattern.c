#include<stdio.h>
int main(){
    int i,j,k,n=5;
    for(i=1;i<=n;i++){
        for(j=i,k=65;j<=n;j++){
            printf("%c ",k);
            k++;
        }
        for(j=2;j<=i;j++){
            printf("  ");
        }
        for(j=2;j<=i;j++){
            printf("  ");
        }
        for(j=i,k=65+(n- i);j<=n;j++){
            printf("%c ",k);
            k--;
        }
        printf("\n");

    }
    return 0;
}