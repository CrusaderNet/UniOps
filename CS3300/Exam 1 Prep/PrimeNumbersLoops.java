
import java.util.Scanner;

public class PrimeNumbersLoops {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        char exitChar;
        boolean prime = false;
        
        do{
            System.out.print("Enter a positive integer: ");
            int value = sc.nextInt();
            System.out.println("");
            
            System.out.print("The following are all of the prime numbers from 1 up to " + value + ":");
            for(int i = 1; i <= value; i++){
                if(i == 2)
                    prime = true;
                else{
                    for(int j = 2; j < i; j++){
                        if(((i % j) == 0)){
                            prime = false;
                            break;
                        }else
                            prime = true;
                    }
                }
                if(prime)
                    System.out.print(" " + i);
            }
            
            System.out.print("\n\n Do you want to quit?(y/n): ");
            exitChar = sc.next().charAt(0);
            
            System.out.println("\n");
        }while(exitChar != 'Y' && exitChar != 'y');
    }
}
