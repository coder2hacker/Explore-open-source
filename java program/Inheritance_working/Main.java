package Practical5;

import java.util.Scanner;

public class Main {       
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ch;
        char i ;       
        do{  
        System.out.println(" 1. Bicycle details \n 2. Car details \n 3.Bike details ");
        System.out.print(" Enter the choice from (1 to 3) : ");
        ch = sc.nextInt();
                  
        switch(ch){
            case 1 :
               Bicycle b = new Bicycle();
               b.change_gear();
               b.speed();
               b.apply_Brakes();
               break;
            case 2 :
               Car c = new Car(); 
               c.change_gear(); 
               c.speed();
               c.apply_Brakes();
               break;
            case 3:
               Bike k = new Bike(); 
               k.change_gear();
               k.speed();
               k.apply_Brakes();
               break;
            default :
               System.out.println("Enter valid choice !!");
        }
        System.out.println("Do you want to continue(Y/N) : ");
        i = sc.next().charAt(0);
        }while( i =='Y' || i == 'y');
        sc.close();
    }
}
