public class KadaneAlg { 

public static void kadanes(int numbers[]) { // KADANES MAX. SUMARRAY SUM T.C= O(n)
        int ms = Integer.MIN_VALUE; // storing min value in maximum sum
        int cs = 0; // current sum

        for (int i = 0; i < numbers.length; i++) {
            cs = cs + numbers[i];

            if (cs < 0) {
                cs = 0;
            }
            ms = Math.max(cs, ms); // compare cs and ms, and then it stored in ms variable
        }
        System.out.println("our maximum sub array sum is = " + ms);
    }

  public static void main(String args[]) { // main function
    int numbers[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
        kadanes(numbers);
   }
}
