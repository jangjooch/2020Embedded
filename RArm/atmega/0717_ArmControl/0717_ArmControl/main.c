

/*
 * 0717_ArmControl.c
 *
 * Created: 2020-07-17 오전 10:53:06
 * Author : 301-PC-21
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>


volatile unsigned long idx = 0;
volatile unsigned long timer = 0;
volatile unsigned long pwmValue = 0;
volatile long setAngel = 90;
	
long mapping(long x, long in_min, long in_max, long out_min, long out_max);

int main(void)
{
	
		UCSR0A = 0x00;
		UCSR0B = 0x18;
		UCSR0C = 0x06;
		UBRR0H = 0;
		UBRR0L = 103;
	
    /* Replace with your application code */
	
	TCCR1B = 0x01;
	// 1 분주율
	TIMSK |= (1<<TOIE1);
	TCNT1 = -300;
	
	TCCR3A = 0x82;
	TCCR3B = 0x1A;
	TCCR3C = 0x00;
	ICR3 = 40000;
	DDRE |= 0x08;
	
	EICRA = 0x01;
	EIMSK = 0x01;
	
	DDRC = 0xF0;
	
	sei();
	
    while (1) 
    {
		if(pwmValue > 80){
			setAngel = setAngel + 1;
		}
		else if(pwmValue < 60){
			setAngel = setAngel - 1;
		}
		
		if(setAngel > 180)
		    setAngel = 180;
		else if(setAngel < 0)
		    setAngel = 0;
		OCR3A = mapping(setAngel, 0, 180, 1000, 5000);
		_delay_ms(100);
		// 딜레이가 없으면 너무 많은 경우를 인식하여 진행에 무리가 있음
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
	if( (PIND & 0x01) ){
		PORTC = 0x80;
		timer = idx;
	}
	else{
		PORTC = 0x00;
		if(timer != 0){
			pwmValue = idx - timer;
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

void UART_Putchar(unsigned char data){
	while((UCSR0A & 0x20) == 0x0){
		// UDRE0 이 1이 될때가지 대기
		// 즉 데이터 전송 버퍼가 비일때까지 대기
		// 전송버퍼가 비인다면 1로 Set 됨
		;
	}
	UDR0 = data;
	//데이터 씀
}