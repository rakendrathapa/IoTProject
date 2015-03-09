/* 
 * File:   urt.c
 * Author: fanny
 *
 * Created on February 2, 2015, 7:32 PM
 */

#include <p18f4620.h>
#include "Header.h"

/*
 * 
 */
static unsigned char c=0;
static unsigned char timeout=0;

void  main()
{
    SPBRGH=0x00;
    SPBRG=0xCF;
    TXSTA=0x04;
    RCSTAbits.SPEN=1;
    PIE1bits.TXIE=1;        //Transmission Interrupt enabled
    
    TXSTAbits.TXEN=1;       //Enable transmission;
    while(1){
        TXREG='F';
        while(!PIR1bits.TXIF);
        TXREG='a';
        while(!PIR1bits.TXIF);
        TXREG='n';
        while(!PIR1bits.TXIF);
        TXREG='n';
        while(!PIR1bits.TXIF);
        TXREG='y';
        while(!PIR1bits.TXIF);
        TXREG='\n';
        while(!PIR1bits.TXIF);
        TXREG='\t';
        while(!PIR1bits.TXIF);
    }
}
