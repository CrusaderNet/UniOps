/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.data;

/**
 *
 * @author Seth
 */
import java.util.Scanner;
import java.util.ArrayList;

public class Data {
    
    Scanner sc = new Scanner(System.in);
    
        private final ArrayList<Integer> numbers;
        
        public Data(){
            this.numbers = new ArrayList<>();
        }

        public void Display_Menu(){
            System.out.println("***************************");
            System.out.println("MAIN MENU");
            System.out.println("0- Quit");
            System.out.println("1- Input Numbers");
            System.out.println("2- Display Numbers");
            System.out.println("3- Search Numbers");
            System.out.println("4- Delete Numbers");
            System.out.println("");
        }
        
        public void Input_Numbers(){
            
            String input;
            int count, num;
            System.out.println("***************************");
            System.out.println("Input Numbers Chosen.");
            System.out.print("How many numbers will you input?: ");
            input = sc.next();
            count = Integer.parseInt(input);
            
            for(int i = 0; i < count; i++){
                System.out.print("Input Target Number " + i + " -> ");
                input = sc.next();
                num = Integer.parseInt(input);
                
                numbers.add(num);
            }
            
            System.out.println("***************************");
        }
        
        public void Display_Numbers(){
            System.out.println("***************************");
            System.out.println("Display Numbers Chosen.");
            System.out.println(numbers);
            System.out.println("***************************");
        }
        
        public void Search_Numbers(){
            
            String input;
            int num;
            boolean isFound = false;
            System.out.println("***************************");
            System.out.println("Search Numbers Chosen.");
            System.out.print("What number do you want to search for?: ");
            input = sc.next();
            num = Integer.parseInt(input);
            
            for(int i = 0; i < numbers.size(); i++){
                if(numbers.get(i) == num){
                    System.out.println(num + " was found at position " + i);
                    isFound = true;
                }
            }
            
            if(!isFound){
                System.out.println(num + " was not found within the ArrayList.");
            }
            
            System.out.println("***************************");
        }
        
        public void Delete_Numbers(){
            System.out.println("***************************");
            System.out.println("Delete Numbers Chosen.");
            numbers.clear();
            System.out.println("***************************");
    }


    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        String input;
        int choice;
        
        Data arrayData = new Data();
        
        do{
            arrayData.Display_Menu();
            System.out.print("Please enter a selection: ");
            input = sc.next();
            choice = Integer.parseInt(input);
            if(choice == 0){
                System.out.println("***************************");
                System.out.println("Quitting. . . . .");
                System.out.println("***************************");
                break;
            }else if(choice == 1){
                arrayData.Input_Numbers();
                continue;
            }else if(choice == 2){
                arrayData.Display_Numbers();
                continue;
            }else if(choice == 3){
                arrayData.Search_Numbers();
                continue;
            }else if(choice == 4){
                arrayData.Delete_Numbers();
                continue;
            }
        }while(choice != 0);
        
    }
}

