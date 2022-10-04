import java.util.Scanner;

class Game {
    private int score = 0, random;

    Game() {
        System.out.println(
                "Game Rules : There is a secret number between 1-100 and you have to guess, you got unlimited attempts.\nThe lesser atempt you take the better you are ... Have Fun !!\n");
        random = (int) (Math.random() * 100);
    }

    public void getScore() {
        System.out.println("Hurray !!! You guessed the secret  number in " + score + " attempt");
    }

    public void setScore() {
        score++;
    }

    public int getUserInput() {
        System.out.print("Enter a Number :");
        Scanner sc = new Scanner(System.in);
        int input = sc.nextInt();
        return input;
    }

    public boolean isCorrect(int num) {
        if (num == random) {
            return true;
        }
        return false;
    }

    public boolean isGreater(int num) {
        if (num > random) {
            return true;
        }
        return false;
    }

    public boolean isSmaller(int num) {
        if (num < random) {
            return true;
        }
        return false;
    }
}

public class GuessTheNumber {

    public static void main(String[] args) {
        int num;
        Game obj = new Game();
        while (true) {
            num = obj.getUserInput();
            if (obj.isCorrect(num)) {
                obj.setScore();
                obj.getScore();
                break;
            } else if (obj.isGreater(num)) {
                System.out.println("The secret number is less than this ...");
            } else if (obj.isSmaller(num)) {
                System.out.println("The secret number is greater than this ...");
            }
            obj.setScore();
        }
    }
}
