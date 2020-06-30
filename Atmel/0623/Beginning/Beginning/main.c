/*
 * Beginning.c
 *
 * Created: 2020-06-23 오후 2:17:31
 * Author : 301-PC-21
 */ 

#include <avr/io.h>
// 레지스터 관리용 헤더파일
#include <avr/delay.h>

int main(void)
{	
    /* Replace with your application code */
	DDRC |= 0x01;
    while (1) 
    {
		PORTC |= 0x01;
		_delay_ms(1000);
		PORTC &= ~(0x01);
		_delay_ms(1000);
    }
}

