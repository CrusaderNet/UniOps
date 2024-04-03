/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.odometer;

/**
 *
 * @author Seth
 */

public class Odometer {
    private int mileage;
    private double fuel;
    private double fuelEff;
    
    public Odometer(){
        mileage = 0;
        fuel = 0;
        fuelEff = 0;
    }
    
    public void setFuelEff(double num){
        fuelEff = num;
    }
    public void addMile(int mile){
        mileage += mile;
        fuel = mileage / fuelEff;
    }
    public void resetOdom(){
        mileage = 0;
        fuel = 0;
    }
    public double currentFuel(){
        return fuel;
    }
    public int currentMile(){
        return mileage;
    }
}
