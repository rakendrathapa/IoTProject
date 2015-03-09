/* 
 * File:   timer1.c
 * Author: fanny
 *
 * Created on January 6, 2015, 5:58 PM
 */

#include "header2.h"
#include <p18f4620.h>

/*
 * 
 */
void main() {

    PORTB=0x00;
    LATB=0x00;
    ADCON1=0x0F;
    TRISB=0xCF;
    TMR0L=0x24;
    TMR0H=0xF4;
    T0CON=0x03;
    T0CONbits.TMR0ON=1;
    while(1)
    {
        if(!TMR0)
        {
            PORTBbits.RB5=!PORTBbits.RB5;
            TMR0H=0xF4;
            TMR0L=0x24;
        }
    }
}


