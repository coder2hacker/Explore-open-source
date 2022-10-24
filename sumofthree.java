import java.util.Scanner;

class SumOfThreeNumbers{
	public static void main(String args[]){
		int num1,num2,num3,result;
		System.out.println("Enter any 3 integers ");
		Scanner in = new Scanner(System.in);
		num1 = in.nextInt();
		num2 = in.nextInt();
		num3 = in.nextInt();
		result=num1+num2+num3;
		System.out.println("The result after addition is "+result);
	}
}
Sample Output