import java.util.Arrays;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;

public class DuplicateWord {

    public static void main(String[] args) {
        String str = "hello there hello hi there hello";

        Map<String, Long> hashMap = Arrays.stream(str.split(" "))
                .collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));
        System.out.println(hashMap);
    }
}
