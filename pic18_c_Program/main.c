/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#endif

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */
#include "printf.h"
#include "sralloc.h"
/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

void main(void)
{
    unsigned char *a;
    int *data;
    unsigned char *Name;

    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    InitApp();
    /* TODO <INSERT USER APPLICATION CODE HERE> */
    printf("Hello World\n");
    a = (unsigned char *)SRAMalloc(sizeof(unsigned char));
    data = (int *)SRAMalloc(sizeof(int));
    Name = (unsigned char *)SRAMalloc(9*sizeof(unsigned char));

    *a = 'a';
    *data=200;
    *Name='P';
    *(Name+1)='r';
    *(Name+2)='a';
    *(Name+3)='n';
    *(Name+4)='e';
    *(Name+5)='y';
    *(Name+6)='T';
    *(Name+7)='h';
    *(Name+8)='\0';
    while(1)
    {
        printf("a=%c\tdataDec=%d\tdataHex=%x\tName=%s\r\n", *a, *data, *data, Name);
    
    }
    SRAMfree(a);
    SRAMfree(data);
    SRAMfree(Name);
}

