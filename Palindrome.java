import java.util.Scanner;

public class Palindrome {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a number to check for Palindrome :");
        int num = input.nextInt();
        input.close();
        int res = 0, rem;
        int q = num;

        while (q != 0) {
            rem = q % 10;
            res = res * 10 + rem;
            q = q / 10;
        }
        if (res == num) {
            System.out.println("The number is palindrome ...");
        } else {
            System.out.println("The number is not palindrome ...");
        }
    }
}
