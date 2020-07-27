/*
 * 0717_ArmControlCom01.c
 *
 * Created: 2020-07-17 오후 3:22:38
 * Author : 301-PC-21
 */ 

#include <avr/io.h>

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>


volatile unsigned long idx = 0;
volatile unsigned long timer[5] = {0, 0, 0, 0, 0};
volatile unsigned long pwmValue[5] = {0, 0, 0, 0, 0};
volatile long setAngel[5] = {90, 90, 90, 90, 90};


long mapping(long x, long in_min, long in_max, long out_min, long out_max);


int main(void)
{
	
	TCCR1B = 0x01;
	// 1 분주율
	TIMSK |= (1<<TOIE1);
	TCNT1 = -300;
	
	// Motor 제어 Duty Cycle 생성 16bit timer
	TCCR3A = 0xAA; // 1010 1010
	// COMA1 COMA0 : 1 0 -> ICR3을 만나면 Clear
	// COMB1 COMB0 : 1 0 -> ICR3을 만나면 Clear
	// COMC1 COMC0 : 1 0 -> ICR3을 만나면 Clear
	// WGM11 WGM10 : 1 0 -> 14번모드 1 1 1 0 을 위함
	TCCR3B = 0x1A;
	// WGM13 WGM12 : 1 1 -> 14번모드 1 1 1 0 을 위함
	// CS12 CS11 CS10 : 분주율 8 -> 0 1 0 을 위함
	TCCR3C = 0x00;
	// PWM모드에서는 출력할 것이 없다.
	ICR3 = 40000;
	// TOP 설정
	// 분주 = 1/16 * 8 * 40000 = 20000nanoSec = 20ms
	// Duty Cycle 설정
	DDRE |= 0x38;
	
	EICRA = 0x05;
	EIMSK = 0x03;
	
	DDRB = 0xF0;
	
	sei();
	
    /* Replace with your application code */
    while (1) 
    {
		OCR3A = mapping(setAngel[0], 0, 180, 1000, 5000);
		OCR3B = mapping(setAngel[1], 0, 180, 1000, 5000);
    }
}




ISR(TIMER1_OVF_vect){
	TCNT1 = -300;
	idx = idx + 1;
	if(idx > 60000){
		idx = 0;
	}
}


ISR(INT0_vect){
	if( (PIND & 0x01 ) ){
		timer[0] = idx;
	}
	else{
		if(timer[0] != 0){
			pwmValue[0] = idx - timer[0];
			if(pwmValue[0] > 80){
				setAngel[0]++;
			}
			else if(pwmValue[0] < 60){
				setAngel[0]--;
			}
			if(setAngel[0] > 180){
				setAngel[0] = 180;
			}
			else if(setAngel[0] < 0){
				setAngel[0] = 0;
			}
		}
	}
}

ISR(INT1_vect){
	if( (PIND & ( 0x02 ) ) ){
		timer[1] = idx;
	}
	else{
		if(timer[1] != 0){
			pwmValue[1] = idx - timer[1];
			if(pwmValue[1] > 80){
				setAngel[1]++;
			}
			else if(pwmValue[1] < 60){
				setAngel[1]--;
			}
			if(setAngel[1] > 180){
				setAngel[1] = 180;
			}
			else if(setAngel[1] < 0){
				setAngel[1] = 0;
			}
		}
	}
}

long mapping(long x, long in_min, long in_max, long out_min, long out_max)
{
	if(x > in_max){
		x = in_max;
	}
	else if(x < in_min){
		x = in_min;
	}
	unsigned long result = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
	return result;
}