/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.pumpeffcalc;

/**
 *
 * @author Seth
 */

//MonthData Class, Used to store all DayData objects in a Month of data
public class MonthData {
    private DayData[] data;
    private double monthAvg;
    
    public MonthData(String month){
        switch(month){
            case "January": data = new DayData[31];
                break;
            case "February": data = new DayData[29];
                break;
            case "March": data = new DayData[31];
                break;
            case "April": data = new DayData[16];
                break;
            default: break;
        }
    }
    
    //Mutator
    public void setMonthData(DayData day, int index){
        data[index] = day;
    }
    
    //Accessor to get the Efficiency average from a specific day
    public double getDayAvg(int index){
        return data[index].getAvgEff();
    }
    
    //Recursive Function to get the average of all Efficiency Data in one month
    public double getMonthAvg(int index,int sum){
        if(index == data.length)
            return (double) sum/data.length;
        else{
            sum += data[index].getAvgEff();
            index++;
        }
        return getMonthAvg(index, sum);
    }
    
}
