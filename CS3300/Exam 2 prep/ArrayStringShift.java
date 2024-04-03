/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.arraystringshift;

/**
 *
 * @author Seth
 */

import java.util.Scanner;

public class ArrayStringShift { 
    
    static int IntValidation(String str_input){
        
        int intNum;
        Scanner sc = new Scanner(System.in);
        
        while(true){
            try{
                intNum = Integer.parseInt(str_input);
                break;
            }catch(Exception e){
                System.out.print("ERROR: Invalid shift integer. Enter a valid integer: ");
            }
            str_input = sc.next();
            System.out.println("");
        }
        
        return intNum;
    }
    
    public static void main(String[] args) {
        
        String orig_string, str_num_shift, result;
        int num_shift, length;
        char shifted_array[];
        char response;
        Scanner sc = new Scanner(System.in);
        
        do
        {
            System.out.print("Enter a string: ");
            orig_string = sc.next();

            length = orig_string.length();
            shifted_array = new char[length];

            System.out.print("\nInput the number of shifts: ");
            str_num_shift = sc.next();
            System.out.println("");
            num_shift = IntValidation(str_num_shift);

            for(int i = 0; i < length; i++){
                shifted_array[i] = orig_string.charAt((i + num_shift) % length);
            }

            result = String.valueOf(shifted_array);

            System.out.println("Original String = " + orig_string);
            System.out.println("Shifted String = " + result);
            System.out.println("Number of Shifts= " + num_shift);

            System.out.print("\nDo you want to quit?(y/n): ");
            response = sc.next().charAt(0);
        }while(response != 'y' && response != 'Y');
        
    }
}
