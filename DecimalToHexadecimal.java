import java.util.Scanner;
 
public class DecimalToHexaDecimal
{   
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
         
        //Taking input from the user
         
        System.out.println("Enter The Decimal Number : ");
         
        int inputNumber = sc.nextInt();
         
        //Copying inputNumber into copyOfInputNumber
         
        int copyOfInputNumber = inputNumber;
         
        //Initializing hexa to empty string
         
        String hexa = "";
         
        //Digits in HexaDecimal Number System
         
        char hexaDecimals[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
         
        //Defining rem to store remainder
         
        int rem = 0;
         
        //See the below explanation to know how this loop works
         
        while (inputNumber > 0)
        {
            rem = inputNumber%16;
             
            hexa =  hexaDecimals[rem] + hexa;
             
            inputNumber = inputNumber/16;
        }
         
        System.out.println("HexaDecimal Equivalent of "+copyOfInputNumber+" is "+hexa);
    }
}