/*
 * 0701_PWM_Read01.c
 *
 * Created: 2020-07-01 오후 1:44:32
 * Author : 301-PC-21
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

int main(void)
{
    TCCR0 = 0x83;
	//FOC0 WGM01 COM01 COM00 WGM00 CS02 CS01 CS00
	//  x	 1		1	 1		1	1	  0	   0
	// FOC0 PWM모드이기에 상관 없음
	// WGM01 00
	//    0   1 : phase Correct PWM
	//    1   1 : Fast PWM
	// COM01 00
	//   1	  0 : OCRA0 이상 LOW
	//	 1	  1 : OCRA0 이상 HIGH
	// CS02 01 00
	//   1   0  0 : 분주율 64 설정
	
	TIMSK |= (1<<OCIE0);
	// OCIE0 Enable
	// OCIE2 TOIE2 TICIE1 OCIE1B TOIE1 <OCIE0 TOIE0>
	//									  1	
	// PB4 에서 출력이 감지될 것이다.
    while (1) 
    {
		// PWM 신호읽고
		// 이를 기반으로 출력 DutyCycle 설정
		
		
		
    }
}

ISR(TIMER0_COMP_vect){
	
}