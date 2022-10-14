import java.io.*;

import java.util.*;

//Program to calculate Nth Catalan Number using dynamic programming
public class Main {

  public static void main(String[] args) throws Exception {
    Scanner scn = new Scanner(System.in);

    int n = scn.nextInt();

    long[] dp = new long[n + 1];
    dp[0] = 1; //since 0th Catalan number is 1

    dp[1] = 1; //since 1st Catalan number is also 1

    for (int i = 2; i < dp.length; i++) {
      for (int j = 0; j < i; j++) {
        dp[i] += dp[j] * dp[i - 1 - j];
      }
    }

    System.out.println(dp[n]);  //nth Catalan number
  }

}