
public class CryptarithmeticLoop {

    public static void main(String[] args) {
        for(int T = 0; T < 10; T++){
            for(int O = 0; O < 10; O++){
                if(T != O){
                    for(int G = 0; G < 10; G++){
                        if(T != G && O != G){
                            for(int D = 0; D < 10; D++){
                                if(T != D && O != D && G != D){
                                    int TOO = T * 100 + O * 10 + O;
                                    int GOOD = G * 1000 + O * 100 + O * 10 + D;
                                    if(TOO + TOO + TOO + TOO == GOOD){
                                        System.out.println("Solution Letter Values: ");
                                        System.out.println("T: " + T);
                                        System.out.println("O: " + O);
                                        System.out.println("G: " + G);
                                        System.out.println("D: " + D);
                                        System.exit(0);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
