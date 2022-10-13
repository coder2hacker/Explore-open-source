import java.util.Arrays;
import java.util.Random;
import java.util.stream.IntStream;
import net.coderodde.util.sorting.Introsort;

/**
 * This class implements a demonstration of Introsort's performance as compared 
 * to {@link java.util.Arrays.sort}.
 * 
 * @author Rodion "rodde" Efremov
 * @version 1.6
 */
public class Demo {

    private static final int LENGTH = 5000000;
    private static final int ITERATIONS = 30;

    public static void main(String[] args) {
        long seed = System.currentTimeMillis();
        System.out.println("Seed: " + seed);
        Random random = new Random(seed);

        long totalArraysSort = 0L;
        long totalHeapsort = 0L;

        for (int iteration = 0; iteration < ITERATIONS; ++iteration) {
            int[] array1 = getRandomIntegerArray(LENGTH, random);
            int[] array2 = array1.clone();

            int fromIndex = random.nextInt(LENGTH / 10);
            int toIndex = LENGTH - random.nextInt(LENGTH / 10);

            long startTime = System.currentTimeMillis();
            Arrays.sort(array1, fromIndex, toIndex);
            long endTime = System.currentTimeMillis();

            totalArraysSort += endTime - startTime;
            System.out.println("Arrays.sort in " + (endTime - startTime) + 
                               " milliseconds.");

            startTime = System.currentTimeMillis();
            Introsort.sort(array2, fromIndex, toIndex);
            endTime = System.currentTimeMillis();

            totalHeapsort += endTime - startTime;
            System.out.println("Introsort.sort in " + (endTime - startTime) + 
                               " milliseconds");

            if (!Arrays.equals(array1, array2)) {
                throw new RuntimeException("Sorts do not agree.");
            }
            System.out.println("Arrays identical: true");
            System.out.println("---");
        }

        System.out.println("Total Arrays.sort time:    " + totalArraysSort + 
                           " milliseconds.");
        System.out.println("Total Introsort.sort time: " + totalHeapsort +
                           " milliseconds.");
    }

    private static int[] getRandomIntegerArray(int size, Random random) {
        return IntStream.range(0, size)
                        .map((i) -> random.nextInt(2 * size))
                        .toArray();
    }
}
