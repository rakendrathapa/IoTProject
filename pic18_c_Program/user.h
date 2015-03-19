/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/
#ifndef __USER_H
#define __USER_H
/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

extern void InitializeUSART(void);   //Initialize USART as Asyn 8bit running at 9600Baud rate
void putc( void* p, char Txdata);           //System provided implementation of the putchar function
extern void InitializeTimer0(void);  //InitializeTimer0 to work as tick
extern void InitializeGPIOs(void);          //Initialize GPIOs; calls various required GPIOs to be used.
extern void ConfigurePortB(void);           //Configure PORTB
extern void EnableInterrupt(void);   //Enable Interrupts
extern void InitApp(void);           //I/O and Peripheral Initialization 
#endif