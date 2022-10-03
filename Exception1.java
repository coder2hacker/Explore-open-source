import java.util.*;
public class Exception1 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a,b,result;
		System.out.println("Enter the valyue of a and b: ");
		a=sc.nextInt();
		b=sc.nextInt();
		try {
		/*
		  This try{} block will hold those code ehich
		  may generate exxeption.
		  This try{} block will always be executed. 
		  If any exception occurs, then only catch() {} block will be executed. 
		  Otherwise catch() {} will not be executed.
		 */
			result=a/b;
			System.out.println("the result is: "+result);
		}
		catch(Exception e){
		/*
		  	e is a reference to the instance of the Exception.
		  	
		 */
			System.out.println(e); //It will print the Exception.
			System.out.println("b can't be 0.");
		}
		
		sc.close();
	}

}

/*
 	If only the value od b = 0, then try block will generate
 	java.lang.ArithmeticException: / bu zero 
 	then catch(){} block will be executed. 
 */
