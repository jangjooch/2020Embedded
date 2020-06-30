/*
 * UART_Beginning03.c
 *
 * Created: 2020-06-24 오후 2:05:59
 * Author : 301-PC-21
 */ 

long map01(long x, long in_min, long in_max, long out_min, long out_max);

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>


long mapping(long x, long in_min, long in_max, long out_min, long out_max);

int main(void)
{	
	long ad_val = 0;
	
	UCSR0A = 0x00;
	UCSR0B = 0x08;
	UCSR0C = 0x06;
	UBRR0H = 0;
	UBRR0L = 103;	
		
	// ADC INPUT
	ADCSRA = 0x87;
	//ADCSRA = (1<<ADEN) | (1<<ADSC) | (1<<ADFR) |(7<<ADPS0);
	//ADCSRA = (1<<ADEN) | (7<<ADPS0);
	// ADEN ADSC ADFR ADIF | ADIE ADPS2 ADPS1 ADPS0
	// ADEN = ADC Enable Set
	// 분주율 128 설정
		
	ADMUX = 0x40;
	//REFS1 REFS0 ADLAR MUX4 | MUX3 MUX2 MUX1 MUX0
	// AVCC 5V
	// AREF 전압단자 이용
	// AREF단자와 GND 사이를 콘센터로 접속
	//ADMUX = (1<<REFS0)|(6<<MUX0);
	// ADC 0 번사용
    /* Replace with your application code */
	_delay_ms(5);
    while (1) 
    {
		
		//ADCSRA = 0xC7;
		// 0b1100 0111
		ADCSRA |= (1<<ADSC);				
		while( ( (ADCSRA & 0x40) != 0)){
			// AD변환이 끝나 0이 되었을때			
			;
		}				
		ADCSRA |= (1<<ADIF);
		
		//ad_val = ADCL + (ADCH << 8);		
		//unsigned char val = (unsigned char)mapping(ad_val, 0,0xFFFF,0,250);				
		
		UART_Putchar(0xFF);
		UART_Putchar(0xFF);
		
		//UART_Putchar(0x41);
		//UART_Putchar(0x42);
		//UART_Putchar(val);
		UART_Putchar(ADCL); // LOW부터 읽어야 Register 가 Reset 되어 다시 쓸수 있다.
		UART_Putchar(ADCH);		
		UART_Putchar(0xFE);
		UART_Putchar(0xFE);
		
		//ADCSRA = 0x00;
		while((UCSR0A & 0x20) == 0x0){
			// 너무 빠른 시간내에 계속 전송하기 때문에 데이터가 쌓여
			// 수신받는 곳에서 이를 처리하기 위해 시간이 많이 소요됨으로
			// 한번 값을 처리했을때, delay되도록 하는 것이다.
			;
		}
		
		_delay_ms(500);
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