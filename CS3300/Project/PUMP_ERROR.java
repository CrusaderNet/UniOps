/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.pumpeffcalc;

/**
 *
 * @author Seth
 */

//Exception Class for 0 Pump Average
public class PUMP_ERROR extends Exception {
    public PUMP_ERROR(){
        super("ERROR: PUMP AVERAGE IS AT 0. CHECK PUMP!");
    }
}
