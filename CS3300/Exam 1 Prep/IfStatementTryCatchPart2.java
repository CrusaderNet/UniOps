
import javax.swing.JOptionPane;

public class IfStatementTryCatchPart2 {

    public static void main(String[] args) {
        int a, b;
        String c = "Results";
        
        while(true){
            try{
                a = Integer.parseInt(JOptionPane.showInputDialog("Enter the first number: "));
            }catch(Exception e){
                JOptionPane.showMessageDialog(null, "# is not a valid number.","ERROR", JOptionPane.ERROR_MESSAGE);
                continue;
            }
            break;
        }
        
        while(true){
            try{
                b = Integer.parseInt(JOptionPane.showInputDialog("Enter the second number: "));
            }catch(Exception e){
                JOptionPane.showMessageDialog(null, "# is not a valid number.","ERROR", JOptionPane.ERROR_MESSAGE);
                continue;
            }
            break;
        }
        
        if(a > b){
            JOptionPane.showMessageDialog(null, a + " is greater than " + b, c, JOptionPane.INFORMATION_MESSAGE);
        }else{
            JOptionPane.showMessageDialog(null, b + " is greater than " + a, c, JOptionPane.INFORMATION_MESSAGE);
        }
        
    }
}
