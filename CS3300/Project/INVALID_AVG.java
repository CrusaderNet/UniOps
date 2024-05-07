/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.pumpeffcalc;

/**
 *
 * @author Seth
 */

//Exception Class for Averages that are out of range
public class INVALID_AVG extends Exception {
    
    public INVALID_AVG(){
        super("Invalid Average");
    }
    
}
