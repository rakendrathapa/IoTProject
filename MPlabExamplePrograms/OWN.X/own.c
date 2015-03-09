/* 
 * File:   own.c
 * Author: fanny
 *
 * Created on January 25, 2015, 3:42 PM
 */

#include <p18f4620.h>
#include "Header.h"
#define LED1 PORTBbits.RB5
#define LED2 PORTBbits.RB4
static unsigned timing=0;
static unsigned count=0;
static unsigned beatFlag=0;

void beat1()
{
    if(timing){
        switch(count){
            case 0:
                LED1=1;
                LED2=0;
                break;
            case 1:
                LED1=0;
                break;
            case 2:
                LED1=1;
                break;
            case 3:
                LED1=0;
                break;
            case 4:
                LED1=1;
                break;
            case 5:
            case 6:
                LED1=0;
                break;
            case 7:
                LED2=1;
                break;
            default:
                break;
        }
        if(count<7)
            count++;
        else
            count=0;
        timing=0;
    }
}

void beat2()
{
    if(timing){
        switch(count){
            case 0:
                LED1=1;
                LED2=0;
                break;
            case 1:
                LED1=0;
                break;
            case 2:
                LED1=1;
                break;
            case 3:
                LED1=0;
                break;
            case 4:
                LED1=1;
                break;
            case 5:
            case 6:
                LED1=0;
                break;
            case 7:
                LED2=1;
                break;
            default:
                break;
        }
        if(count<7)
            count++;
        else
            count=0;
        timing=0;
    }
}

void beat3(){
    if(timing){
        switch(count){
            case 0:
                LED1=1;
                LED2=0;
                break;
            case 1:
                LED1=0;
                LED2=1;
                break;
             case 2:
                LED1=1;
                LED2=0;
                break;
             case 3:
                LED1=0;
                LED2=1;
                break;
             case 4:
             case 5:
             case 6:
             case 7:
                LED1=1;
                LED2=0;
                break;

             default:
                break;
        }
        if(count<7)
            count++;
        else
            count=0;
        timing=0;
    }
}
/*
 * 
 */
void main() {
//PORTB configuration
    PORTB=0x00;
    LATB=0x00;
    TRISB=0xCF;
    ADCON1=0x0F;

 //TIMER configuration
    TMR0H=0xF4;
    TMR0L=0x24;
    T0CON=0x03;
//    T0CONbits.TMR0ON=1;

//INTERRUPT configuration
    INTCON=0x00;
    INTCON3=0x48;
    INTCONbits.PEIE=1;
    INTCONbits.GIE=1;

    while(1){
        if(beatFlag){
            switch(beatFlag){
                case 1:
                    beat1();
                    break;
                case 2:
                    beat2();
                    break;
                case 3:
                    beat3();
                    break;
                default:
                    break;

            }
        }
    }
}

void interrupt ISR(){
    if(INTCON3bits.INT1IF){
        if(beatFlag == 0){
            beatFlag=1;
            INTCONbits.INT0IE=1;
            T0CONbits.TMR0ON=1;
            INTCONbits.TMR0IE=1;
        }
        else{
            beatFlag=0;
            INTCONbits.INT0IE=0;
            T0CONbits.TMR0ON=0;
            INTCONbits.TMR0IE=0;
        }
        LED1=LED2=0;
        count=0;
        timing=0;
        INTCON3bits.INT1IF = 0;
    }
    if(INTCONbits.INT0IF){
        if((beatFlag<=3) && (beatFlag>0))
            beatFlag++;
        else
            beatFlag=1;
        count=0;
        LED1=LED2=0;
        INTCONbits.INT0IF=0;
    }

   if(INTCONbits.TMR0IF){
       if(beatFlag==1)//beat1 running
       {
             TMR0H=0xF4;
             TMR0L=0x24;
       }
       else if(beatFlag==2)// beat2 running
       {
           TMR0H=0x61;
           TMR0L=0xA8;
       }
       else if(beatFlag==3)// beat3 running
       {
            TMR0H=0x50;
            TMR0L=0x00;
       }
       timing=1;
       INTCONbits.TMR0IF=0;
   }
}