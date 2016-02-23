/*
* File:   leds.c
* Author: 
*
* Created on December 27, 2014, 1:31 PM
*/

#include <xc.h>
#include "leds.h"

#define TRIS_RUN TRISGbits.TRISG12
#define TRIS_STOP TRISGbits.TRISG14
#define ODC_RUN ODCGbits.ODCG12
#define ODC_STOP ODCGbits.ODCG14
#define RUN_LED LATGbits.LATG12 // TRD1
#define STOP_LED LATGbits.LATG14 // TRD2

#define ON 1
#define OFF 0

#define INPUT 1
#define OUTPUT 0

void initLEDs(){
    //TODO: Initialize the appropriate pins to work with the LEDs
    TRIS_RUN = OUTPUT;
    TRIS_STOP = OUTPUT;

    //ODC_RUN = 1;
    //ODC_STOP = 1;
    
    RUN_LED = OFF;
    STOP_LED = OFF;
    
}

void runLED(){
 
    RUN_LED = ON;
    STOP_LED = OFF;
}

void stopLED(){
 
    STOP_LED = ON;
    RUN_LED = OFF;
    
}