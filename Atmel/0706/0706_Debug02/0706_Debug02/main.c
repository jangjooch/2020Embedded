/*
 * 0706_Debug02.c
 *
 * Created: 2020-07-06 오후 2:08:50
 * Author : 301-PC-21
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT4_vect){
	PORTC = 0xF0;
}
ISR(INT5_vect){
	PORTC = 0x0F;
}	

int main(void)
{
	DDRC = 0xFF;
	DDRE = 0x00;
	
	EICRB = (2<<INT4) | (2<<INT5);
	EIMSK = (1<<INT4) | (1<<INT5);
	
	
	sei();
	
    /* Replace with your application code */
    while (1) 
    {
		
    }
}

