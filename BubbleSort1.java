import java.util.*;
class BubbleSort1{
    // Bubble Sort Function 
    public static void BubbleSort(int arr[]){
        for(int i=0;i<=arr.length-1;i++){
            // Inner loop to visit two adjacent elements
            for(int j=0;j<arr.length-1-i;j++){
                // Swaping two adjacent elements 
                if (arr[j]>arr[j+1]){
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
    }
    // Function to print Array
    public static void PrintArray(int arr[]){
        for (int i=0;i<arr.length;i++)
            System.out.print(arr[i]+" ");
    }

    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int arr[]=new int[5];
        for(int i=0;i<arr.length;i++)
            arr[i]=sc.nextInt();
        sc.close();

        BubbleSort(arr);
        PrintArray(arr);
    }
} 