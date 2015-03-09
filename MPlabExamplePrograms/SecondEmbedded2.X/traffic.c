/* 
 * File:   traffic.c
 * Author: fanny
 *
 * Created on December 31, 2014, 6:45 PM
 */

#include <p18f4620.h>
#include "config.h"
#define MIN 20000
#define LEDRED PORTBbits.RB5
#define LEDGREEN PORTBbits.RB4
/*
 * 
 */



void main()
{
    PORTB=0x00;
    LATB=0x00;
    ADCON1=0x0F;
    TRISB=0xCF;
    LEDGREEN=0;
    LEDRED=1;
    unsigned int i,j;
    while(1){
        for(i=0;i<MIN;i++)
            for(j=0;j<3;j++);
        LEDRED =0;
        LEDGREEN=1;
        for(i=0;i<MIN;i++)
            for(j=0;j<5;j++);
        LEDGREEN =0;
        LEDRED =1;
    }
}
    

        


    





    


