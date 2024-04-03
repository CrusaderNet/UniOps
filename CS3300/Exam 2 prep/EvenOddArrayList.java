/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.evenoddarraylist;

/**
 *
 * @author Seth
 */
import java.util.ArrayList;
import java.util.Random;

public class EvenOddArrayList {

    public static void main(String[] args) {
        Random rand = new Random();
        
        int arr[][] = new int[5][5];
        
        ArrayList<Integer> even = new ArrayList<>();
        ArrayList<Integer> odd = new ArrayList<>();
        
        System.out.println("Random Numbers: ");
        for(int i = 0; i < arr.length; i++){
            for(int j = 0; j < arr[i].length; j++){
                arr[i][j] = rand.nextInt(100);
                System.out.print(arr[i][j] + " ");
                
                if(arr[i][j] % 2 == 0){
                    even.add(arr[i][j]);
                }else{
                    odd.add(arr[i][j]);
                }
            }
            
            System.out.println();
        }
        
        System.out.println("Even Numbers: " + even);
        System.out.println("Odd Numbers: " + odd);
    }
}
