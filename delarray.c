#include<stdio.h>
int main(){
    int n,arr[100],m;
    int i,j,k,element;
    printf("Enter the limit: ");
    scanf("%d",&n);
    printf("Enter the values: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the value to be deleted: ");
    scanf("%d",&element);
    
    for(i=0;i<n;i++){
        if(arr[i]==element){
            
            for(j=i;j<n;j++){
                arr[j]=arr[j+1];

        }
        n--;
        

        }
        
    }
    printf("Resultant array  : ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}