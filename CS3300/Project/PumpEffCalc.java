/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.pumpeffcalc;

/**
 *
 * @author Seth
 */

//This Program Takes a Text document containing hourly pump efficiency data from Jan 1 to April 16.
//The Program then allows the user to request average efficiency calculations for the entire time period, per month, or on a specific day.
//This program uses a DayData class, which hold data about the pump efficiency for a 24 hour period at a time
//This program uses a MonthData class, which holds an array of DayData objects for a specific month


//Preprocessor Directives
import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import javax.swing.*;

//Main Driver Class PumpEffCalc
public class PumpEffCalc {

    //Main Function
    public static void main(String[] args) {
        
        //Declare new Scanner
        Scanner in = null;
        
        //Try/Catch to catch an error opening the data file
        try{
            in = new Scanner(new FileInputStream("PumpEffData.txt"));
        }catch(FileNotFoundException e){
            JOptionPane.showMessageDialog(null, "File Not Found or Could Not Be Opened!", "ERROR", JOptionPane.ERROR_MESSAGE);
            System.exit(0);
        }
        
        //declare temporary array for taking in each day's data
        int[] input = new int[24];
        
        //Create MonthData object for January
        MonthData jan = new MonthData("January");
        //Insert Each array of 24hour data into a Day Data object and store it in January MonthData
        for(int i = 0; i < 31; i++){
            //Grab Data for a 24hour period
            for(int j = 0; j < 24; j++){
                input[j] = in.nextInt();
            }
            DayData day = new DayData(input);
            tryCalcDayAvg(day, i);
            jan.setMonthData(day, i);
        }
        
        //Create MonthData Object for February
        MonthData feb = new MonthData("February");
        //Insert Each array of 24hour data into a Day Data object and store it in February MonthData
        for(int i = 0; i < 29; i++){
            //Grab Data for a 24hour period
            for(int j = 0; j < 24; j++){
                input[j] = in.nextInt();
            }
            DayData day = new DayData(input);
            tryCalcDayAvg(day, i);
            feb.setMonthData(day, i);
        }
        
        //Create MonthData Object for March
        MonthData mar = new MonthData("March");
        //Insert Each array of 24hour data into a Day Data object and store it in March MonthData
        for(int i = 0; i < 31; i++){
            //Grab Data for a 24hour period
            for(int j = 0; j < 24; j++){
                input[j] = in.nextInt();
            }
            DayData day = new DayData(input);
            tryCalcDayAvg(day, i);
            mar.setMonthData(day, i);
        }
        
        //Create MonthData Object for April, only until the project due date of the 16th
        MonthData apr = new MonthData("April");
        //Insert Each array of 24hour data into a Day Data object and store it in April MonthData
        for(int i = 0; i < 16; i++){
            //Grab Data for a 24hour period
            for(int j = 0; j < 24; j++){
                input[j] = in.nextInt();
            }
            DayData day = new DayData(input);
            tryCalcDayAvg(day, i);
            apr.setMonthData(day, i);
        }
        
        //Open JOptionPane Menu, but first go to Exception Handler for the Menu Method
        menuTryCatchDriver(jan, feb, mar, apr);
        
        //Close the Scanner
        in.close();
        
    }
    
    //Try/Catch Exception Handler Method for the Menu Method
    static void menuTryCatchDriver(MonthData jan, MonthData feb, MonthData mar, MonthData apr){
        try{
            //Try to start the Menu Method
            menuAvgEff(jan, feb, mar, apr);
        }
        //Catch any Exception and display an error if the Menu Method throws an exception
        catch(Exception e){
            JOptionPane.showMessageDialog(null, "Error Detected when Running Menu Driver!", "ERROR", JOptionPane.ERROR_MESSAGE);
            System.exit(0);
        }
    }
    
    //Method to Try/Catch exception handle the math for having a DayData Object calculate and update it's 24hour Efficiency Average
    static void tryCalcDayAvg(DayData day, int index){
        try{
            day.calcDayAvgEff();
        }
        //Handle an Exception thrown when the Average Efficiency is >100 or <0
        catch(INVALID_AVG a){
            JOptionPane.showMessageDialog(null, "Day " + index + "'s Average is Invalid! Check Dataset!", "ERROR", JOptionPane.ERROR_MESSAGE);
        }
        //Handle and Exception thrown when a Day's Average is 0, to detect failed Pumps
        catch(PUMP_ERROR b){
            JOptionPane.showMessageDialog(null, "Day " + index + "'s Data Has a Pump Failure!", "ERROR", JOptionPane.ERROR_MESSAGE);
        }
    }
    
    
    //Menu Driver Method. Displays the Menu and also allows calculation of final averages to display
    static void menuAvgEff(MonthData jan, MonthData feb, MonthData mar, MonthData apr){
        
        //Opening Menu
        String choice1;
        
        //Menu For Loop
        do{
            //Opening Menu
            String[] choices = {"January", "February", "March", "April", "All Months", "QUIT"};
            choice1 = (String)JOptionPane.showInputDialog(null, "Select an option to compile data on:", "Average Pump Efficiency Calculator", JOptionPane.QUESTION_MESSAGE, null, choices, "January");
            
            if(choice1.equals("January")){
                //Menu Level 2, Determining if user wants data displayed for specific day or whole month.
                String[] choiceSTR = {"Specific Day", "Whole Month"};
                int choice2 = JOptionPane.showOptionDialog(null, "Select an option to compile data on:", "Average Pump Efficiency Calculator", 0, 3, null, choiceSTR, "Specific Day");

                if(choice2 == 0){
                    int choice3 = Integer.parseInt(JOptionPane.showInputDialog(null, "Input the Specific Day Number(Between 1 and 31):", "Specific Day Avg Pump Efficiency",JOptionPane.QUESTION_MESSAGE));
                    JOptionPane.showMessageDialog(null, "The Average Pump Efficiency on " + choice1 + " " + choice3 + " is " + jan.getDayAvg(choice3 - 1) + "%", "Average Pump Efficiency", JOptionPane.INFORMATION_MESSAGE);
                }else if(choice2 == 1){
                    JOptionPane.showMessageDialog(null, "The Average Pump Efficiency for " + choice1 + " is " + jan.getMonthAvg(0, 0) + "%", "Average Pump Efficiency", JOptionPane.INFORMATION_MESSAGE);
                }
            }

            else if(choice1.equals("February")){
                //Menu Level 2, Determining if user wants data displayed for specific day or whole month.
                String[] choiceSTR = {"Specific Day", "Whole Month"};
                int choice2 = JOptionPane.showOptionDialog(null, "Select an option to compile data on:", "Average Pump Efficiency Calculator", 0, 3, null, choiceSTR, "Specific Day");

                if(choice2 == 0){
                    //For Specific Day, Input Specific day, fetch average efficiency and display on JOptionPane
                    int choice3 = Integer.parseInt(JOptionPane.showInputDialog(null, "Input the Specific Day Number(Between 1 and 29):", "Specific Day Avg Pump Efficiency",JOptionPane.QUESTION_MESSAGE));
                    JOptionPane.showMessageDialog(null, "The Average Pump Efficiency on " + choice1 + " " + choice3 + " is " + feb.getDayAvg(choice3 - 1) + "%", "Average Pump Efficiency", JOptionPane.INFORMATION_MESSAGE);
                }else if(choice2 == 1){
                    JOptionPane.showMessageDialog(null, "The Average Pump Efficiency for " + choice1 + " is " + feb.getMonthAvg(0, 0) + "%", "Average Pump Efficiency", JOptionPane.INFORMATION_MESSAGE);
                }
            }

            else if(choice1.equals("March")){
                //Menu Level 2, Determining if user wants data displayed for specific day or whole month.
                String[] choiceSTR = {"Specific Day", "Whole Month"};
                int choice2 = JOptionPane.showOptionDialog(null, "Select an option to compile data on:", "Average Pump Efficiency Calculator", 0, 3, null, choiceSTR, "Specific Day");

                if(choice2 == 0){
                    //For Specific Day, Input Specific day, fetch average efficiency and display on JOptionPane
                    int choice3 = Integer.parseInt(JOptionPane.showInputDialog(null, "Input the Specific Day Number(Between 1 and 31):", "Specific Day Avg Pump Efficiency",JOptionPane.QUESTION_MESSAGE));
                    JOptionPane.showMessageDialog(null, "The Average Pump Efficiency on " + choice1 + " " + choice3 + " is " + mar.getDayAvg(choice3 - 1) + "%", "Average Pump Efficiency", JOptionPane.INFORMATION_MESSAGE);
                }else if(choice2 == 1){
                    JOptionPane.showMessageDialog(null, "The Average Pump Efficiency for " + choice1 + " is " + mar.getMonthAvg(0, 0) + "%", "Average Pump Efficiency", JOptionPane.INFORMATION_MESSAGE);
                }
            }

            else if(choice1.equals("April")){
                //Menu Level 2, Determining if user wants data displayed for specific day or whole month.
                String[] choiceSTR = {"Specific Day", "Whole Month"};
                int choice2 = JOptionPane.showOptionDialog(null, "Select an option to compile data on:", "Average Pump Efficiency Calculator", 0, 3, null, choiceSTR, "Specific Day");

                if(choice2 == 0){
                    //For Specific Day, Input Specific day, fetch average efficiency and display on JOptionPane
                    int choice3 = Integer.parseInt(JOptionPane.showInputDialog(null, "Input the Specific Day Number(Between 1 and 16):", "Specific Day Avg Pump Efficiency",JOptionPane.QUESTION_MESSAGE));
                    JOptionPane.showMessageDialog(null, "The Average Pump Efficiency on " + choice1 + " " + choice3 + " is " + apr.getDayAvg(choice3 - 1) + "%", "Average Pump Efficiency", JOptionPane.INFORMATION_MESSAGE);
                }else if(choice2 == 1){
                    JOptionPane.showMessageDialog(null, "The Average Pump Efficiency for " + choice1 + " is " + apr.getMonthAvg(0, 0) + "%", "Average Pump Efficiency", JOptionPane.INFORMATION_MESSAGE);
                }
            }

            //Option Chosen - All Months. Calculate the average of all Days of data and display.
            else if(choice1.equals("All Months")){
                JOptionPane.showMessageDialog(null, "The Average Pump Efficiency for this year so far is " + (jan.getMonthAvg(0, 0) + feb.getMonthAvg(0, 0) + mar.getMonthAvg(0, 0) + apr.getMonthAvg(0, 0))/4 + "%", "Average Pump Efficiency", JOptionPane.INFORMATION_MESSAGE);
            }

            else if(choice1.equals("QUIT")){
                JOptionPane.showMessageDialog(null, "QUITTING. . .", "Average Pump Efficiency", JOptionPane.INFORMATION_MESSAGE);
                break;
            }
        
        }while(!choice1.equals("QUIT"));
    }
}
