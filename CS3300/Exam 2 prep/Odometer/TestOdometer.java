/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.odometer;

/**
 *
 * @author Seth
 */

public class TestOdometer {
    
    public static void main(String[] args){
        Odometer odom = new Odometer();
    
        odom.setFuelEff(22.1);
        odom.addMile(321);
        
        System.out.println("For your Fuel Efficient Car: ");
        System.out.println("After " + odom.currentMile() + " miles, " + odom.currentFuel() + " gallons used");
        
    }
    
    
}
