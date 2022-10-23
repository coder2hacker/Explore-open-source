class Solution {
    public int removeDuplicates(int[] arr) {
        int i=1;
        boolean b=false;
        int count=1;
        while(i<arr.length ){
            if(arr[i-1]!=arr[i]){
                arr[count]=arr[i];
                b=false;
                count++;
            }else if(arr[i-1]==arr[i] && !b){
                 arr[count]=arr[i];
                  b=true;
                count++;
            }
            i++;
        }
        return count++;
    }
}
