import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.Arrays;  
public class MyClass {
    public static final Function<String,String> toUpperCase = (s) -> Arrays.asList(s.replaceAll("[*0-9]", "").split("")).stream().map(i->i.toUpperCase()).collect(Collectors.joining());
    public static void main(String args[]) {
      System.out.println(toUpperCase.apply("github"));
      System.out.println(toUpperCase.apply("abcdef"));
      System.out.println(toUpperCase.apply("ga11w"));
      System.out.println(toUpperCase.apply("1435raaww"));
    }
}
//OUTPUT IS 
// GITHUB
// ABCDEF
// GAW
// RAAWW
