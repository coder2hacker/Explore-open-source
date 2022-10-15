public class reverseArr {
    public static void main(String[] args) {
        int []arr={1,2,3,4,5,6,7,8};


    }
    static void reverse(int arr[]){
        int start=0;
        int end=arr.length-1;
        while(start<end){
            swap(arr,start,end);

        }


    }
    static void swap(int arr[],int index1,int index2){
        int temp=arr[index1];
    }

}
