/* 
 * File:   INT2.c
 * Author: fanny
 *
 * Created on January 22, 2015, 10:53 PM
 */

#include<p18f4620.h>
#include "Header.h"

#define LED1 PORTBbits.RB4
#define LED2 PORTBbits.RB5

//#define BUTTON INTCONbits.INT0IF
static unsigned char timeout=0;
static unsigned char countBeat=0;
static unsigned char beatFlag=0;

void beat1()
{
    if(timeout){
        switch(countBeat){
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
        if(countBeat < 12)
            countBeat++;
        else
            countBeat=0;

        timeout=0;
    }
}

void beat2()
{
    if(timeout){
        switch(countBeat){
            case 0:
            case 3:
            case 4:
                LED1=1;
                LED2=0;
                break;

           case 6:
           case 2:
           case 1:
               LED1=0;
               LED2=1;
               break;

            default:
               break;
        }
        if(countBeat < 12)
            countBeat++;
        else countBeat=0;
        timeout=0;
    }
}

void beat3()
{
    if(timeout){
        switch(countBeat){
            case 0:
            case 3:
            case 4:
                LED1=1;
                LED2=0;
                break;

           case 6:
           case 2:
           case 1:
               LED1=0;
               LED2=1;
               break;

            default:
               break;
        }
        if(countBeat < 12)
            countBeat++;
        else countBeat=0;
        timeout=0;
    }
}

/*
 * 
 */
void main() {
    /*portB configuration*/
    PORTB=0x00;
    LATB=0x00;
    ADCON1=0x0F;
    TRISB=0xCF;

    /*interupt configuration*/
    INTCON=0x30;
    INTCONbits.PEIE=1;
    INTCONbits.GIE=1;

    /*timer configuration*/
    //Initially Configure Timer for Beat1 -> beacause Beat 1 is initial Beat
    TMR0H=0xF4;
    TMR0L=0x24;

    T0CON=0x03;
    T0CONbits.TMR0ON=1;
    
    while(1){
        switch(beatFlag){
            case 0:
                beat1();
                break;
            case 1:
                beat2();
                break;
            case 2:
                beat3();
                break;
            default:
                break;

        }
    }
}

void interrupt ISR()
{
    if(INTCONbits.INT0IF){
        if(beatFlag < 2)
            beatFlag++;
        else
            beatFlag=0;

        countBeat=0;
        LED1=LED2=0;
        INTCONbits.INT0IF=0;
    }
    
    if(INTCONbits.TMR0IF){
        if(beatFlag==0){  //Beat1 running -> set Timer = 0.5s
            TMR0H=0xF4;
            TMR0L=0x24;
        }
        else if(beatFlag==1){   //if Beat2 running -> set Timer=0.2s
            TMR0H=0x7A;
            TMR0L=0x12;;
        }
        else if(beatFlag==2){   //if Beat" running -> set Timer=xsecs
            TMR0H=0xFF;
            TMR0L=0x00;
        }
        timeout=1;
        INTCONbits.TMR0IF=0;
    }

    /** WIll never execute*/
    /** HW: You need to tell me why*/
    /*
    if(INTCONbits.TMR0IF){
        TMR0H=0x61;
        TMR0L=0xA8;
        timeout=1;
        INTCONbits.TMR0IF=0;
    }/*****because it has not been explicited
     * for which one of the functions this code should
     * execute; I should have put the execution of these codes under the
     * condition of one of the 2 functions being in a running state.****
     */
}
