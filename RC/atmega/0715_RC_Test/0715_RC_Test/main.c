/*
 * 0715_RC_Test.c
 *
 * Created: 2020-07-15 오후 3:30:59
 * Author : 301-PC-21
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned int idx1 = 0;

volatile unsigned int timer[5] = {0, 0, 0, 0, 0};
volatile unsigned int pwm_value[5] = {0, 0, 0, 0, 0};

char flag00 = 0;

int main(void)
{
	
	UCSR0A = 0x00;
	UCSR0B = 0x18;
	UCSR0C = 0x06;
	UBRR0H = 0;
	UBRR0L = 103;
	
	
	// 노말모드
	TCCR1B = 0x02;
	// 8분주율
	TIMSK = (1<<TOIE1);
	// TImer 1 Overflow Enable
	TCNT1 = -20000;
	// 시작값이 0에서 -2000 되것이기에 오버플로우로 인하여 65xxxx-2000이 된 것이다.
	// 1/16 * 8 * 2000 = 1000;
	
	
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
    while (1) 
    {
		
    }
}

ISR(TIMER1_OVF_vect){
	
	TCNT1 = -20000;
	idx1  = idx1 + 1;
}

ISR(INT0_vect){
	UART_Putchar(0x63);
	if(PIND & 0x01){
		timer[0] = idx1;
		UART_Putchar(0x62);
	}
	else{
		UART_Putchar(0x61);
		if(timer[0] != 0){
			pwm_value[0] = idx1 - timer[0];
			flag00 = 1;
		}
	}
	
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