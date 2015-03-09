/* 
 * File:   beat1.c
 * Author: fanny
 *
 * Created on January 2, 2015, 1:06 PM
 */

#include <p18F4620.h>
#include "header1.h"
#define LED1 PORTBbits.RB4
#define LED2 PORTBbits.RB5

/*
 * 
 */
static unsigned char timeout=0;
void main() {
    /** PortB configuration*/
    PORTB=0x00;
    LATB=0x00;
    ADCON1=0x0F;
    TRISB=0xCF;

    /**Interrupt Configuration*/
    INTCON=0x20;    //unmask timer0 interrupt
    INTCONbits.PEIE=1;
    INTCONbits.GIE=1;

    /** Timer Configuration*/
    TMR0H=0xF4;
    TMR0L=0x24;
    T0CON=0x03;
    T0CONbits.TMR0ON=1;

    unsigned char count=0;
    while(1){
        if(timeout){
            switch(count){
                case 0:
                case 2:
                case 8:
                    LED1=1;
                    break;
                case 1:
                    LED1=0;
                    break;
                case 3:
                case 9:
                    LED1=0;
                    LED2=1;
                    break;
                case 4:
                case 10:
                    LED2=0;
                    break;
                default:
                    break;
            }
            if(count<12)
                count++;
            else count=0;
            timeout=0;
        }
        else{}
    }
}

void interrupt ISR()
{
    if(INTCONbits.TMR0IF){
        TMR0H=0xF4;
        TMR0L=0x24;
        timeout=1;
        INTCONbits.TMR0IF=0;
    }
}
