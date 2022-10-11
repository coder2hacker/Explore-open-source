#include<stdio.h>
int main(){
    int arr[100],i,j,count,n;
    printf("No. of elements: ");
    scanf("%d",&n);
    printf("Elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        count=0;
        for(j=0;j<=n;j++){
            if(i!=j){
                if(arr[i]==arr[j]){
                    count++;
                }
            }
        }
        if(count==0){
            printf("%d ",arr[i]);
        }
    }
    return 0;
}