/*
 * 0716_AtmegaTest.c
 *
 * Created: 2020-07-16 오전 9:02:47
 * Author : 301-PC-21
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

unsigned long idx1 = 0;
unsigned char test = 0;

// Receiver를 통해 받는 값 저장용
unsigned long timer[5] = {0, 0, 0, 0, 0};
unsigned long pwm_value[5] = {0, 0, 0, 0, 0};

long map(long x, long in_min, long in_max, long out_min, long out_max);

int main(void)
{
	
	
	TCCR1B = 0x02;
	TIMSK |= (1 << TOIE1);
	TCNT1 =-2000;
	// 1/16 * 8 * 2000 = 1000
	
	
	TCCR3A = 0x82;
	TCCR3B = 0x1A;
	TCCR3C = 0x00;
	
	ICR3 = 40000;
	
	DDRE = 0x0F;
	// OC3A 출력  -> PE3
	// INT 4 입력 -> PE4
	
	EICRA = 0x55;
	// ISC31 ISC30 ISC21 ISC20 | ISC11 ISC10 ISC01 ISC00
	// INT 3, 2, 1, 0
	// Change 설정//
	EICRB = 0x01;
	// INT 4
	// Change 설정 Change -> 0 1
	EIMSK = 0x1F;
	// INT 0, 1, 2, 3, 4 Enable
	
	sei();
	
	DDRD = 0x00;
	// INT 0, 1, 2, 3 INPUT;
	
	DDRB = 0x03;
	// PB0 : break
	// PB1 : CW/CCW
	/* Replace with your application code */
	PORTB = 0x03;
	
	
    /* Replace with your application code */
    while (1) 
    {
		long result = 1500 - pwm_value[0];
		if(result < 0){
		result = -result;
			PORTB = 0x01;
		}
		else{
			PORTB = 0x03;
		}
		if(result < 100){
			result = 0;
		}
		OCR3A = map(result, 0, 400, 1000, 5000);
		//OCR3A = 30000;
		unsigned long past = idx1;
		while(idx1 - past < 500){
			;
		}
    }
	
	
}

ISR(TIMER1_OVF_vect){
	
	TCNT1 = -20000;
	idx1  = idx1 + 1;
}

ISR(INT0_vect){
	if(PIND & 0x01){
		timer[0] = idx1;
	}
	else{
		if(timer[0] != 0){
			pwm_value[0] = idx1 - timer[0];
		}
	}
	
}
long map(long x, long in_min, long in_max, long out_min, long out_max)
{
	if(x < in_min){
		x = in_min;
	}
	if( x > in_max){
		x = in_max;
		
		
		
	}
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

