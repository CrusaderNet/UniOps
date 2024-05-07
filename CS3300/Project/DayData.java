/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.pumpeffcalc;

/**
 *
 * @author Seth
 */

//DayData Class, Holding data relating to a 24h period of Pump Efficiency Data
public class DayData {
    
    private int[] data;
    private static int length;
    double averageEff;
    
    public DayData(int[] inputData){
        length = 24;
        data = new int[24];
        setData(inputData);
    }
 
    //Mutator, to copy the temp array into the DayData object array(And not just a reference)
    public void setData(int[] inputData){
        for(int i = 0; i < 24; i++){
            data[i] = inputData[i];
        }
    }
    
    //Accessors
    public double getAvgEff(){
        return averageEff;
    }
    
    public int[] getData(){
        return data;
    }
    
    public int getLength(){return length;}
    
    //Calculate Day Average Efficiency, throw an error in an error case
    public void calcDayAvgEff() throws INVALID_AVG, PUMP_ERROR{
        int sum = 0;
        
        for(int i = 0; i < 24; i++){
            sum += data[i];
        }
        
        averageEff = sum / 24;
        
        if(averageEff < 0 || averageEff > 100)
            throw new INVALID_AVG();
        if(averageEff == 0)
            throw new PUMP_ERROR();
    }
    
}
