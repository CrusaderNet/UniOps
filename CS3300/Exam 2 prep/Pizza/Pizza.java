/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.pizzaclass;

/**
 *
 * @author Seth
 */

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
        
    }
