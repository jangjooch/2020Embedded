/*
 * 0706_HW01.c
 *
 * Created: 2020-07-06 오후 2:29:05
 * Author : 301-PC-21
 */ 


#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

char captFlag = 0;
char status = 0;

unsigned int pastICR = 0;
unsigned int currentICR = 0;

unsigned char angleGet = 0;
unsigned char angleStatus = 0;

long mapping(long x, long in_min, long in_max, long out_min, long out_max);

int main(void)
{
	TCCR1A = 0x00;
	// COM1A1 COM1A0 COM1B1 COM1B0 COM1C1 COM1C0 WGM11 WGM10
	// nomal 모드	
	TCCR1B = 0x02;
	// ICNC1 ICES1 WGM13 WGM12 CS12 CS11 CS10
	// ICES3: Input Capture Edge Select
	// 0 이면 하강엣지, 1이면 상승엣지
	// 분주율 64	
	TCCR1C = 0x00;
	// FOC1A FOC1B FOC1C	// OC1 출력 X
	// Input으로 받아 Input Cature형태로 진행해야 하니까
	TIMSK = 0x21;
	TCNT1 = 100;
	// TOP설정
	
	DDRD |= 0x08;
	// PD4가 ICP1 이므로 echo의 값을 받으니 Input 설정
	// PD3은 Trigger 역할을 할것이므로 Output 설정
	
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
	
	UCSR0A = 0x0;
	UCSR0B = 0x98; // RXCIE1 = 1,수신완료 인터럽트 인에이블 , 송수신 인에이블= 1
	UCSR0C = 0x06; // 비동 기, 데이터 8비트 모드
	UBRR0H = 0;
	UBRR0L = 103; //16MHz , BAUD 9600
	
	sei();
    /* Replace with your application code */
	
    while (1) 
    {		
		if(captFlag == 0){
			TCCR1B = 0x42;
			// Input Capture 상승엣지 Set
			PORTD = 0x00;
			_delay_us(1);
			PORTD = 0x08;
			// Trigger Activate
			_delay_us(11);
			TCNT1 = 0;
			PORTD = 0x00;
			
		}
		else if(captFlag == 1){
			if(ICR1 > 65000){
				captFlag == 2;
				pastICR = 0;
				currentICR = 0;
			}
		}
		else if(captFlag == 2){
			unsigned int disGet = (currentICR - pastICR);
			
			disGet = disGet / 12;
			// 8분주율 = 0.000,000,5
			// 1mm = 0.1cm = 0.00000588
			// 1mm가는 시간 / 8분주율 = 11.76 -> 12
			unsigned int valuecm = (unsigned int)disGet/10;			
			unsigned int valuemm = (unsigned int)(disGet%10);						
			
			UART0_Putch(0xFF);
			UART0_Putch(valuecm >> 8);
			UART0_Putch(valuecm & 0xFF);
			UART0_Putch(valuemm);			
			_delay_ms(100);
			TCNT1 = 0;
			// TC
			TCCR1B = 0x42;
			// 기록하였으니 다시 상승엣지 Set
			captFlag = 0;
			currentICR = 0;
			pastICR = 0;
			// 사용했던 Flag와 기록 초기화
		}
    }
}

ISR(USART0_RX_vect){
	angleGet = UDR0;
	long angleSet = mapping((long)angleGet, 0,180,1000,5000);
	OCR3A = angleSet;	
}

ISR(TIMER1_CAPT_vect){
	if(TCCR1B & 0x40){
		// 상승엣지 인경우
		pastICR = ICR1;
		TCCR1B = 0x02;
		// 하강엣지 Clear
		captFlag = 1;
	}
	else{
		// 하강엣지 인경우
		// 시작 pastICR이 기록되었을때 작동되면 현재를 기록
		if(captFlag == 1){
			currentICR = ICR1;
			captFlag = 2;
		}
	}
}

void UART0_Putch(unsigned char data) // 송신
{
	while(!(UCSR0A & 0x20));
	UDR0 = data;
}


long mapping(long x, long in_min, long in_max, long out_min, long out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}