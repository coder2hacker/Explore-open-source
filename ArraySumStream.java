import java.util.Arrays;

public class ArraySumStream {

    public static void main(String[] args) {
        int[] array = {10, 20, 30};
        int sum = Arrays.stream(array).reduce(Integer::sum).getAsInt();
        System.out.println(sum);

        Arrays.stream(array).reduce(Integer::sum).ifPresent(System.out::println);
    }
}
