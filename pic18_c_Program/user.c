/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#define USE_OR_MASKS
#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>    /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#endif
#include "user.h"
#include "timers.h"
#include "usart.h"
#include "sralloc.h"
#include "printf.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */
void InitializeUSART(void)
{
    unsigned char config=0, spbrg=0, baudconfig=0, i=0;
    CloseUSART();   //turn off usart if was previously on
    //-----configure USART -----
    config = USART_TX_INT_OFF | USART_RX_INT_OFF | USART_ASYNCH_MODE | USART_EIGHT_BIT |
    USART_CONT_RX | USART_BRGH_LOW;
    //-----SPBRG needs to be changed depending upon oscillator frequency-------
    spbrg = 12; //At 8Mhz of oscillator frequency & baud rate of 9600.
    OpenUSART(config, spbrg); //API configures USART for desired parameters
    baudconfig = BAUD_8_BIT_RATE | BAUD_AUTO_OFF;
    baudUSART (baudconfig);
    return;
}
//single USART character transmission
void putc( void* p, char Txdata)
{
    while(BusyUSART()); //Check if Usart is busy or not
    putcUSART(Txdata); //transmit the string
    return;
}

void InitializeTimer0(void)
{
     unsigned char config=0x00;
     unsigned int timer_value=0;

     //configure Timer0
     timer_value=0xFFFF - 0x1F4 + 0x02;         // = need 500 ticks for 1 millisec (10^3 sec) @8MHz looses 2 at load
     config = TIMER_INT_ON | T0_16BIT | T0_SOURCE_INT | T0_PS_1_4;
     OpenTimer0(config);        //API configures the Timer1 as per user defined.
     WriteTimer0(timer_value); 
}
void InitializeGPIOs(void)
{
    ConfigurePortB();
}

void ConfigurePortB(void)
{
    PORTB=0x00;             //Initialize PORTB by clearing output and data latches
    LATB =0x00;             //Clear PORTB latch
    ADCON1 = 0x0F;          //Set RB<4:0> digital IO pins; Though not required since config bit PBADEN is unset
    TRISBbits.TRISB4=0;    //Setting RB4 as output pin.
}
void EnableInterrupt(void)
{
    /* Set the priority of various interrupts*/
    //Setting timer0 (systick) timer as low priority
    INTCON2bits.TMR0IP=0;   //timer0 Low priority set

    RCONbits.IPEN=1;        //Enabling priority on interrupts
    INTCONbits.GIEH=1;      //Enable all high priority interrupts
    INTCONbits.GIEL=1;      //Enable all low priority peripheral interrupts
}

void InitApp(void)
{
    /* Initialize User Ports/Peripherals/Project */
    INTCON=0x00;
    InitializeTimer0();
    InitializeUSART();
    /* Setup analog functionality and port direction */

    /* Initialize peripherals */
    InitializeGPIOs();
    
    EnableInterrupt();

    /* Initialize user defined Software routines here*/
    init_printf(NULL,putc);
    SRAMInitHeap();
}

