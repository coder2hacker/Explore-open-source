import java.util.*;
public class Main {
  public static int OctaltoDecimal(int Octal) 
  {
    int Decimal = 0;
    int i = 0;
    while (Octal != 0)
    {
      int rem = Octal % 10;
      
      Decimal += rem * Math.pow(8, i);
      i++;
      Octal /= 10;
    }
    
    return Decimal;
  }
  public static void main(String[] args)
  {
    int Octal = 345;
    System.out.println("The decimal equivalent of the given octal number is 
    "+OctaltoDecimal(Octal));
  }
 
}
