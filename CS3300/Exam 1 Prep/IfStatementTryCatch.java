
import javax.swing.*;
import java.lang.String;

public class IfStatementTryCatch {

    public static void main(String[] args) {
        int a, b;
        String c = "Results";
        
        try{
            a = Integer.parseInt(JOptionPane.showInputDialog("Input the first number: "));
            b = Integer.parseInt(JOptionPane.showInputDialog("Input the second number: "));
            
            if(a > b){
                JOptionPane.showMessageDialog(null, a + " is greater than " + b, c, JOptionPane.INFORMATION_MESSAGE);
            } else{
                JOptionPane.showMessageDialog(null, b + " is greater than " + a, c, JOptionPane.INFORMATION_MESSAGE);
            }
            
        } catch(Exception e){
            JOptionPane.showMessageDialog(null, "# is not a valid number.", "ERROR", JOptionPane.ERROR_MESSAGE);
        }
        
    }
}
