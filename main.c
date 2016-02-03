#include <msp430.h>
#include "dio.h"

/*
 * main.c
 */

#define LED1	BIT0
#define LED2	BIT6

void p13Int(void);
void p17Int(void);

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    /* adding interrupt is as simple as a function
     * call with port, pin, and function pointer */
    DIO_enableInterrupt(1, 3, &p13Int);
    DIO_enableInterrupt(1, 7, &p17Int);

    P1DIR |= (LED1 | LED2);	// use to light the LEDs
    P1OUT |= (LED1 | LED2);	// turn the LEDs on

    return 0;
}

void p13Int(void){
	/* using the 'dio' files, we can easily
	 * manipulate this interrupt or other interrupts */
	DIO_disableInterrupt(1, 7);

	P1OUT ^= LED1;	// toggle LED1
}

void p17Int(void){
	DIO_disableInterrupt(1, 3);

	P1OUT ^= LED2;	// toggle LED2
}
