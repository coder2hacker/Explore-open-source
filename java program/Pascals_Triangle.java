public class Pascals_Triangle {

  public static void main(String[] args) {
    int rows = 6, rem = 1;

    for(int i = 0; i < rows; i++) {
      for(int space = 1; space < rows - i; ++space) {
        System.out.print("  ");
      }

      for(int j = 0; j <= i; j++) {
        if (j == 0 || i == 0)
          rem = 1;
        else
          rem = rem * (i - j + 1) / j;

        System.out.printf("%4d", rem);
      }

      System.out.println();
    }
  }
}
