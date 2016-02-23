/*
 * File:   switch.c
 * Author: Garrett
 *
 * Created on September 19, 2015, 10:46 AM
 */

#include <xc.h>
#include <sys/attribs.h>
#include "switch.h"

void initSW2(){
    //TODO: Initialize the appropriate pins to work with the external switch using a
    //change notification interrupt.
    TRISAbits.TRISA7 =1;  // enable input switch 
    CNCONAbits.ON =1; // enable interrupt
    CNENAbits.CNIEA7 =1; // enable interrupt SW2
    IEC1bits.CNAIE= 1; 
    IFS1bits.CNAIF = 0; 
    IPC8bits.CNIP = 3;          
    CNPUAbits.CNPUA7 = 1;
}
