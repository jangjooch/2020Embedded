/*
 * 0723_RC_CombineTest.c
 *
 * Created: 2020-07-23 오후 4:03:11
 * Author : 301-PC-21
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

int main(void)
{
	
	TCCR1A = 0xAA;
	TCCR1B = 0x1A;
	TCCR1C = 0x00;
	ICR1 = 40000;
	DDRB = 0xF0;
	
	TCCR3A = 0x
	
    /* Replace with your application code */
    while (1) 
    {
		
    }
}

