/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.pizza;

/**
 *
 * @author Seth
 */
import java.util.Scanner;

public class Pizza{
    
        private String size;
        private int cheeseTop;
        private int pepTop;
        private int hamTop;
        
        public Pizza(){
            size = "none";
            cheeseTop = 0;
            pepTop = 0;
            hamTop = 0;
        }
        public Pizza(String s, int cT, int pT, int hT){
            size = s;
            cheeseTop = cT;
            pepTop = pT;
            hamTop = hT;
        }
        
        public String getSize(){return size;}
        public int getCT(){return cheeseTop;}
        public int getPT(){return pepTop;}
        public int getHT(){return hamTop;}
        
        public void setSize(String s){size = s;}
        public void setCT(int ct){cheeseTop = ct;}
        public void setPT(int pt){pepTop = pt;}
        public void setHT(int ht){hamTop = ht;}
        
        public double calcCost(){
            if(size.equalsIgnoreCase("Small")){
                return 10 + (cheeseTop * 2) + (pepTop * 2) + (hamTop * 2);
            }else if(size.equalsIgnoreCase("Medium")){
                return 12 + (cheeseTop * 2) + (pepTop * 2) + (hamTop * 2);
            }else if(size.equalsIgnoreCase("Large")){
                return 14 + (cheeseTop * 2) + (pepTop * 2) + (hamTop * 2);
            }
            return -1;
        }
        
        public String getDescription(){
            String desc = "Size: " + size + ", Cheese Toppings: " + cheeseTop + ", Pepperoni Toppings: " + pepTop + ", Ham Toppings: " + hamTop + ", Cost: " + calcCost();
            
            return desc;
        }
       
        public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        int number, cT, pT, hT;
        double total = 0;
        String input, size;
        
        System.out.print("How many Pizzas do you want?: ");
        input = sc.next();
        number = Integer.parseInt(input);
        
        for(int i = 0; i < number; i++){
            System.out.print("What size pizza do you want your pizza to be: Small, Medium or Large?: ");
            size = sc.next();
            
            System.out.print("How many cheese toppings do you want?: ");
            input = sc.next();
            cT = Integer.parseInt(input);
            
            System.out.print("How many pepperoni toppings do you want?: ");
            input = sc.next();
            pT = Integer.parseInt(input);
            
            System.out.print("How many ham toppings do you want?: ");
            input = sc.next();
            hT = Integer.parseInt(input);
            
            Pizza pie = new Pizza(size, cT, pT, hT);
            
            System.out.println(pie.getDescription());
            total += pie.calcCost();
            
            
        }
        
        System.out.println("The total cost is: " + total);
        
    }
}
