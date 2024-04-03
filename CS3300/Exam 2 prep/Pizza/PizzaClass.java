/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.pizzaclass;

/**
 *
 * @author Seth
 */

import java.util.Scanner;

public class PizzaClass {
    
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


