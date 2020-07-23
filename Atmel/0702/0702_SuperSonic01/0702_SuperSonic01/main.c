

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

char captFlag = 0;
char status = 0;
int main(void)
{
    /* Replace with your application code */
	
	
	
	TCCR1A = 0x00;	
	// COM1A1 COM1A0 COM1B1 COM1B0 COM1C1 COM1C0 WGM11 WGM10	
	// nomal 모드
	
	TCCR1B = 0x03;
	// ICNC1 ICES1 WGM13 WGM12 CS12 CS11 CS10
	//  ICES3: Input Capture Edge Select
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
	
	 UCSR0A = 0x0;
	 UCSR0B = 0x98; // RXCIE1 = 1,수신완료 인터럽트 인에이블 , 송수신 인에이블= 1
	 UCSR0C = 0x06; // 비동기, 데이터 8비트 모드
	 UBRR0H = 0;
	 UBRR0L = 103; //16MHz , BAUD 9600
		
	sei();
	
    while (1) 
    {
		if(status == 0){
			PORTD = 0x00;
			// Trigger OUTPUT
			_delay_us(1);
			PORTD = 0x08;
			_delay_us(11);
			PORTD = 0x00;
			//TCNT1 = 100;
			TCNT1 = 0;
			status = 1;
		}
		
		if(captFlag){
			
			//double valueGet = ICR1 * 0.0002 * 64 *4;
			//unsigned int value = (unsigned int)valueGet - 10;
			
			double valueGet = ICR1 * 34000 / 1000000;
			unsigned int value = (unsigned int)valueGet;
			//value = value/58;
			
			unsigned char image = 0;
			if(value > 30){
				image = 0;				
			}
			else if(value > 20){
				image = 1;
			}
			else if(value > 10){
				image = 2;
			}
			else{
				image = 3;
			}
			
			unsigned char valueL = (unsigned char)(value & 0xFF);
			unsigned char valueH = (unsigned char)(value >> 8);
			
			status = 0;
			captFlag = 0;
			
			UART0_Putch(0xFF);
			UART0_Putch(value & 0xFF);
			UART0_Putch(value >> 8);
			UART0_Putch(image);
			_delay_ms(100);
		}
    }
}

void UART0_Putch(unsigned char data) // 송신
{
	while(!(UCSR0A & 0x20));
	UDR0 = data;
}

ISR(TIMER1_CAPT_vect){
	captFlag = 1;
}