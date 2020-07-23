/*
 * 0716_Arm_Servo_test01.c
 *
 * Created: 2020-07-16 오전 10:41:03
 * Author : 301-PC-21
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned long idx = 0;
volatile unsigned long timerSet = 0;
volatile unsigned long pwmValue = 0;

long mapping(long x, long in_min, long in_max, long out_min, long out_max);

int main(void)
{
    /* Replace with your application code */
	
	
	TCCR1B = 0x01;
	// 8분주율
	TIMSK = (1<<TOIE1);
	// TImer 1 Overflow Enable
	TCNT1 = -300;
	// 시작값이 0에서 -2000 되것이기에 오버플로우로 인하여 65xxxx-2000이 된 것이다.
	// 1/16 * 8 * 2000 = 1000;
	// 16비트범위 : 0 ~ 65535

	// 1분주율 -8000 -> 1/16 * 1 * 8000 = 500;
	// 50 ~ 90. 중간 : 70
	
	// Motor 제어 Duty Cycle 생성 16bit timer
	TCCR3A = 0x82;
	// COMA1 COMA0 : 1 0 -> ICR1을 만나면 Clear
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
	DDRE = 0x0F;
	// OC3A 출력  -> PE3
	// INT 4 입력 -> PE4
	DDRC = 0xF0;
	
	// pwm 입력측정을 위한 외부 Interrupt
	EICRA = 0x01;
	// ISC31 ISC30 ISC21 ISC20 | ISC11 ISC10 ISC01 ISC00
	// INT 3, 2, 1, 0
	// Change 설정
	//EICRB = 0x01;
	// INT 4
	// Change 설정 Change -> 0 1
	EIMSK = 0x01;
	// INT 4, 3, 2, 1, 0 Enable
	
	sei();
	
    while (1) 
    {
		if(pwmValue <0){
			pwmValue = -pwmValue;
		}
		//OCR3A = mapping(idx, 50, 60000, 1000, 5000);
		OCR3A = mapping(pwmValue, 50, 90, 1000, 5000);
		//OCR3A = 5000;
    }
}
// PD0
ISR(INT0_vect){
	if( (PIND & 0x01) == 0x01 ){
		PORTC = 0x80;
		timerSet = idx;
	}
	else{
		PORTC = 0x00;
		if(timerSet != 0){
			pwmValue = idx - timerSet;
		}
	}
}

ISR(TIMER1_OVF_vect){
	TCNT1 = -300;
	idx = idx + 1;
	if(idx > 60000){
		idx = 0;
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
