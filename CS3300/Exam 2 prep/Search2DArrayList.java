/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.search2darraylist;

/**
 *
 * @author Seth
 */
import java.util.ArrayList;
import java.util.Arrays;

public class Search2DArrayList {

    public static void main(String[] args) {
        
        ArrayList<ArrayList<Integer>> data1 = new ArrayList<ArrayList<Integer>>();
        data1.add(new ArrayList<>(Arrays.asList(1,1,3,1,5)));
        data1.add(new ArrayList<>(Arrays.asList(1,1,3,1,5)));
        data1.add(new ArrayList<>(Arrays.asList(1,1,3,1,5)));
        data1.add(new ArrayList<>(Arrays.asList(1,1,3,1,5)));
        data1.add(new ArrayList<>(Arrays.asList(1,1,3,1,5)));
        
        ArrayList<ArrayList<Integer>> data2 = new ArrayList<ArrayList<Integer>>();
        data2.add(new ArrayList<>(Arrays.asList(1,2,3,4,5,6,7,8,9,10)));
        data2.add(new ArrayList<>(Arrays.asList(-2,-1,2,1)));
        data2.add(new ArrayList<>(Arrays.asList()));
        data2.add(new ArrayList<>(Arrays.asList(2,2,2)));
        
        System.out.println("Data1 Results: ");
        Display_Locations(SearchEven(data1));
        
        System.out.println("Data2 Results: ");
        Display_Locations(SearchEven(data2));
        
    }
    
    static ArrayList<Integer> SearchEven(ArrayList<ArrayList<Integer>> data) {
        ArrayList<Integer> index = new ArrayList<Integer>();
        
        for(int i = 0; i < data.size(); i++){
            for(int j = 0; j < data.get(i).size(); j++){
                if((data.get(i).get(j)) % 2 == 0){
                    index.add(i);
                    index.add(j);
                }
            }
        }
        
        if(index.isEmpty()){
            index.add(-1);
        }
        
        return index;
    }
    
    static void Display_Locations(ArrayList<Integer> index){
        
        if(index.get(0) != -1){
            for(int i = 0; i < index.size(); i++){
                if(i % 2 != 0 || i == 0){
                    System.out.print(index.get(i) + " ");
                }else{
                    System.out.println();
                    System.out.print(index.get(i) + " ");
                }
            }
        }else{
            System.out.println("This Vector did not have any even numbers.");
        }
    }


}