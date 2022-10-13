public class Demo{
   static int temp;
   static void Cocktail(int a[], int n){
      boolean swap = true;
      int begin = 0,i;
      int end = n - 1;
      while (swap) {
         swap = false;
         for (i = begin; i < end; ++i){
            if (a[i] > a[i + 1]){
               temp = a[i];
               a[i]=a[i+1];
               a[i+1]=temp;
               swap = true;
            }
         }
         if (!swap)
         break;
         swap = false;
         for (i = end - 1; i >= begin; --i){
            if (a[i] > a[i + 1]){
               temp = a[i];
               a[i]=a[i+1];
               a[i+1]=temp;
               swap = true;
            }
         }
         ++begin;
      }
   }
   public static void main(String[] args) {
      int my_arr[] = {34, 78, 90, 32, 67, 12, 1, 0, 95};
      Cocktail(my_arr, my_arr.length);
      System.out.println("The sorted array is ");
      for (int i = 0; i < my_arr.length; i++)
      System.out.print(my_arr[i]+" ");
      System.out.println();
   }
}
