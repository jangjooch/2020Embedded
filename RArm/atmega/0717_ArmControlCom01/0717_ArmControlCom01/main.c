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
	
	TCCR3A = 0x82;
	TCCR3B = 0x1A;
	TCCR3C = 0x00;
	ICR3 = 40000;
	DDRE |= 0x08;
	
	EICRA = 0x55;
	EIMSK = 0x0F;
	
	DDRB = 0xF0;
	
	sei();
	
    /* Replace with your application code */
    while (1) 
    {
		int maxIdx = 0;
		
		long dis1 = 0;		
		long dis2 = 0;
		
		if(pwmValue[maxIdx] < 70){
			dis1 = 70 - pwmValue[maxIdx];
		}
		else{
			dis1 = pwmValue[maxIdx] - 70;
		}

		if(pwmValue[1] < 70){
			dis2 = 70 - pwmValue[1];
		}
		else{
			dis2 = pwmValue[1] - 70;
		}

		if(dis1 < dis2){
			maxIdx = 1;
			PORTB = 0x40;
		}
		else{
			PORTB = 0x80;
		}
		
		if(pwmValue[maxIdx] > 80){
			setAngel[maxIdx] = setAngel[maxIdx] + 1;
		}
		else if(pwmValue[maxIdx] < 60){
			setAngel[maxIdx] = setAngel[maxIdx] - 1;
		}
		
		if(setAngel[maxIdx] > 180)
		
		
		
		
			setAngel[maxIdx] = 180;
		
		else if(setAngel[maxIdx] < 0)
			setAngel[maxIdx] = 0;
		
		OCR3A = mapping(setAngel[maxIdx], 0, 180, 1000, 5000);
		
		_delay_ms(100);
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
			}
		}
}

void intMethod(int a){
	if( (PIND & ( 1<<a ) ) ){
		timer[a] = idx;
	}
	else{
		if(timer[a] != 0){
			pwmValue[a] = idx - timer[a];
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