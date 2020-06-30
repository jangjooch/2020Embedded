/*
 * 0625_HW01.c
 *
 * Created: 2020-06-25 오후 1:40:24
 * Author : 301-PC-21
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

unsigned char led = 1;

int main(void)
{
    /* Replace with your application code */
	
	DDRD = 0xF0;
	PORTD = 0x03;
	DDRB = 0xFF;
	
	EICRA = 0b00001010;
	// Falling Edge
	EIMSK = 0x03;
	// INT0 INT1 Enable
		
	UCSR0A = 0x00;
	// RXCn TXCn UDREn FEn | DORn UPEn U2Xn MPCMn
	// 비동기 방식
	// 멀티프로세서 통신모드 Enable -> 0이 Enable임
	UCSR0B = 0x98;
	// RXCIEn TXCIEn UDRIEn RXENn | TNENn UCSZ2n RXB8n TXB8n
	// RXCIE 수신완료 Interrupt Enable Set
	// RXENn 수신기 Enable Set
	// TNENn 송신기 Enable Set
	UCSR0C = 0x06;
	// UMSELn UPMn1 UPMn0 USBSn | UCSZn1 UCSZn0 UCPOLn
	// 비동기 모드
	// 패리티모드 사용 안함
	// UCSZn1 UCSZn0 -> 전송 데이터 비트 수 설정.-> 011 = 8비트. 즉 char단위
	// 클럭 극성 선택 X. 동기모드에서만 사용
	UBRR0H = 0;
	UBRR0L = 103; //buad Rate
	
	sei();
	
    while (1) 
    {
		PORTB = ~led;		
		UART_Putchar(led);
		_delay_ms(100);		
    }
}

ISR(USART0_RX_vect){
	unsigned char data;
	data = UDR0;
	// 수신버퍼에서 데이터 읽음
	led = data;
}

ISR(INT0_vect){
	if(led & 0x80){
		// 밀려나갈 대상이 1일 경우
		led <<= 1;
		
		led |= 0x01;
		// 밀려나갔던 1이 뒤에와서 Set 설정
	}
	else{
		// 밀려나갈 대상이 0일 경우
		led <<= 1;
	}	
}

ISR(INT1_vect){
	if(led & 0x01){
		// 땡겨져 나갈 대상이 1일 경우
		led >>= 1;
		
		led |= 0x80;
		// 나갔던 1을 머리에 Set
	}
	else{
		led >>= 1;
		// 땡겨져 나갈 대상이 0일 경우
		led &= ~(0x80);
		// MSB 0으로 Clear 혹시모르니까 unsigned이긴 하지만
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