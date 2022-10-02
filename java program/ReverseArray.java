public class ReverseArray {
    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8 };
        System.out.println("array before reverseing :");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        int s = 0, e = arr.length - 1;
        for (int i = 0; i < arr.length; i++) {
            if (s >= e) {
                break;
            } else {
                int temp;
                temp = arr[s];
                arr[s] = arr[e];
                arr[e] = temp;
              
                s++;
                e--;
            }
        }
        System.out.println("\narray after reverseing :");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }

}
