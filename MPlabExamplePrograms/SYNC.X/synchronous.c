#include<p18f4620.h>
#include"header2.h"
#define button PORTBbits.RB5

static unsigned flag=0;


int click()
{
    TXREG='W';
    while(!PIR1bits.TXIF);
    TXREG='A';
    while(!PIR1bits.TXIF);
    TXREG='I';
    while(!PIR1bits.TXIF);
    TXREG='T';
    while(!PIR1bits.TXIF);
    TXREG='_';
    while(!PIR1bits.TXIF);
    TXREG='P';
    while(!PIR1bits.TXIF);
    TXREG='L';
    while(!PIR1bits.TXIF);
    TXREG='E';
    while(!PIR1bits.TXIF);
    TXREG='A';
    while(!PIR1bits.TXIF);
    TXREG='S';
    while(!PIR1bits.TXIF);
    TXREG='E';
    while(!PIR1bits.TXIF);

}


int initialising ()
{
    TXREG='I';
    while(!PIR1bits.TXIF);
    TXREG='n';
    while(!PIR1bits.TXIF);
    TXREG='i';
    while(!PIR1bits.TXIF);
    TXREG='t';
    while(!PIR1bits.TXIF);
    TXREG='i';
    while(!PIR1bits.TXIF);
    TXREG='a';
    while(!PIR1bits.TXIF);
    TXREG='l';
    while(!PIR1bits.TXIF);
    TXREG='i';
    while(!PIR1bits.TXIF);
    TXREG='s';
    while(!PIR1bits.TXIF);
    TXREG='i';
    while(!PIR1bits.TXIF);
    TXREG='n';
    while(!PIR1bits.TXIF);
    TXREG='g';
    while(!PIR1bits.TXIF);
}






void main()
{
    SYNC=1;
    CSRC=1;
    TXSTA=0xA0;
    TXSTAbits.TXEN=1;
    PIE1bits.TXIE=1;
    RCSTA=0x30;
    RCSTAbits.SPEN=1;

    //port config
    PORTB=0x00;
    LATB=0x00;
    ADCON1=0x0F;
    TRISB=0x10;

   //timer config
    TMR0L=0x24;
    TMR0H=0xF4;
    T0CON=0x03;
    T0CONbits.TMR0ON=1;

   //interupt config
    INTCON=0xD6;
    INTCONbits.TMR0IE=1;
    
    while(1){
        initialising();
        if(flag)
            click();
    }
}
   void interrupt  ISR()
   {
         if(INTCONbits.INT0IF){
        if(flag == 0){
            flag=1;
            INTCONbits.INT0IE=1;
            T0CONbits.TMR0ON=1;
        }
            if(INTCONbits.TMR0IF){
       if(flag==1)
       {
             TMR0H=0xF4;
             TMR0L=0x24;
       }
   }

         }