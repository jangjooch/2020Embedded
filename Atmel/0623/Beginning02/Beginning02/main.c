/*
 * Beginning02.c
 *
 * Created: 2020-06-23 오후 3:43:36
 * Author : 301-PC-21
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

char idx = 0;
unsigned long past01 = 0;
unsigned long past02 = 0;
int main(void)
{
    /* Replace with your application code */
	
	DDRD = 0xF0;//PD0, 1 INPUT
	DDRB = 0xFF; // PORTB all OUTPUT
	
	EICRA = 0b00001010; // INT0, 1 Falling Edge 선택
	EIMSK = 0x03; // INT0, 1Enable
	
	SFIOR &= ~(0x04);// Clear
	
	sei(); // Interrupt Enable	
	
	PORTD = 0x03;
	
	
	
    while (1) 
    {
		PORTB = ~(1 << idx);
		_delay_ms(100);
    }
	//cli(); // Interrupt Disable
}

ISR(INT0_vect){
	idx = idx + 1;
	if(idx > 7){
		idx = 0;
	}
}
ISR(INT1_vect){		
	idx = idx - 1;
	if(idx < 0){
		idx = 7;
	}
	
}
