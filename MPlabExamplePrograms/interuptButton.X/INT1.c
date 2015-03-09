/* 
 * File:   INT1.c
 * Author: fanny
 *
 * Created on January 22, 2015, 6:04 PM
 */

#include <p18f4620.h>
#include "header.h"

#define LED PORTBbits.RB5

static unsigned char timeout=0;

int main()
{
    /** PortB configuration*/
    PORTB=0x00;
    LATB=0x00;
    ADCON1=0x0F;
    TRISB=0xDF;

    /**Interrupt Configuration*/
    INTCON=0x10;    //unmask INT0 interrupt
    INTCONbits.PEIE=1;
    INTCONbits.GIE=1;

    while(1);
}

void interrupt ISR()
{
    if(INTCONbits.INT0IF){
        LED=!LED;
        INTCONbits.INT0IF=0;
    }
}