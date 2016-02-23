// ******************************************************************************************* //
//
// File:         lab1p1.c
// Date:         
// Authors:      
//
// Description: Part 1 for lab 1
// ******************************************************************************************* //

#include <xc.h>
#include <sys/attribs.h>
#include "leds.h"
#include "interrupt.h"
#include "switch.h"
#include "timer.h"


/* Please note that the configuration file has changed from lab 0.
 * the oscillator is now of a different frequency.
 */
typedef enum stateTypeEnum{
    led1,led2,debounced1,debounced2
} stateType;

volatile stateType state = led1;

int main(void)
{
    SYSTEMConfigPerformance(50000000);
    
    enableInterrupts();  
    initTimer2();
    initLEDs();
    initSW2();
     
   // state=led1;
    while(1)
    {
        //TODO: Using a finite-state machine, define the behavior of the LEDs
        //Debounce the switch
        switch(state){
            case led1:
                runLED();
                break;
            case led2:
                stopLED();
                break;
            case debounced1:
                delayMs(5);
                break;
            case debounced2:
                delayMs(5);
                break;
        }                  
    }
    
    return 0;
}

void __ISR(_CHANGE_NOTICE_VECTOR, IPL3SRS) _CNInterrupt(void){
    //TODO: Implement the interrupt to capture the press of the button
         IFS1bits.CNAIF = 0;
        if (PORTAbits.RA7==0 && state==led1){
            state=debounced1;
        }
        else if (PORTAbits.RA7==0 && state==led2){
            state=debounced2;
        }
        else if (PORTAbits.RA7==1 && state == debounced1){
            state=led2;
        }
        else if(PORTAbits.RA7==1 && state == debounced2){
            state=led1;
        }

}