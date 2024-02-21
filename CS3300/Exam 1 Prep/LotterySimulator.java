
import java.util.Scanner;
import java.util.Random;

public class LotterySimulator {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num1, num2, num3;
        int iterations = 0;
        
        //Inputs for 3 chosen numbers
        while(true){
            try{
                System.out.print("Enter Number 1: ");
                num1 = Integer.parseInt(sc.nextLine());
            }catch(Exception e){
                System.out.print("Number 1 is an invalid integer or out of range of 0 - 99. Enter Number 1 again: ");
                continue;
            }
            break;
        }
        while(true){
            try{
                System.out.print("Enter Number 2: ");
                num2 = Integer.parseInt(sc.nextLine());
            }catch(Exception e){
                System.out.print("Number 2 is an invalid integer or out of range of 0 - 99. Enter Number 2 again: ");
                continue;
            }
            break;
        }
        while(true){
            try{
                System.out.print("Enter Number 3: ");
                num3 = Integer.parseInt(sc.nextLine());
            }catch(Exception e){
                System.out.print("Number 3 is an invalid integer or out of range of 0 - 99. Enter Number 3 again: ");
                continue;
            }
            break;
        }
        
        boolean lotteryWon = false;
        
        Random r = new Random();
        
        while(lotteryWon == false){
            int randNum1 = r.nextInt(100);
            int randNum2 = r.nextInt(100);
            int randNum3 = r.nextInt(100);
            
            if(num1 == randNum1 && num2 == randNum2 && num3 == randNum3){
                lotteryWon = true;
            }
            
            iterations++;
        }
        
        System.out.println("\nIt took " + iterations + " tries to generate these three numbers " + num1 + " " + num2 + " " + num3);
        
    }
}
