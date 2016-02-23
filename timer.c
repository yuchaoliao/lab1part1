/*
 * File:   timer.c
 * Authors:
 *
 * Created on December 30, 2014, 8:07 PM
 */

#include <xc.h>

/*void initTimer1(){
    //TODO: Initialize Timer 1 to have a period of
    // 1 second. Enable its interrupt
    TMR1 = 0;// clear TMR1
    PR1 = 39061;// Initialize PR1
    T1CONbits.TCKPS = 3; // Initialize pre-scalar
    T1CONbits.TCS = 0; // Setting the oscillator
    IEC0bits.T1IE = 1;// Enable the interrupt
    IFS0bits.T1IF = 0;// Put the flag down
    IPC1bits.T1IP = 3;// Configure the Interrupt Priority
    T1CONbits.TON = 1;// Turn the timer on
}*/

void initTimer2(){
    TMR2 = 0;
    T2CONbits.TCKPS = 0;
    T2CONbits.TCS = 0;
    IFS0bits.T2IF = 0;
}

//Uses timer 2
void delayMs(unsigned int delay){
    //TODO: Create a delay using timer 2 for "delay" microseconds.
    TMR2 = 0;
    PR2 = delay*312;
    IFS0bits.T2IF = 0;
    T2CONbits.ON = 1;
   //IEC1bits.CNAIE = 0;
    while(IFS0bits.T2IF == 0);
    //IEC1bits.CNAIE = 1;
    T2CONbits.ON = 0;
}