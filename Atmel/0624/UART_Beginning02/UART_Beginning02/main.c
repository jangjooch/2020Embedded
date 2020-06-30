/*
 * UART_Beginning02.c
 *
 * Created: 2020-06-24 오후 1:21:57
 * Author : 301-PC-21
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

int main(void)
{
    /* Replace with your application code */
	UCSR0A = 0x00; //  - RXCn TXCn UDREn FEn | DORn UPEn U2Xn MPCMn
	// 비동기 방식
	// 멀티프로세서 통신모드 Enable -> 0이 Enable임
	UCSR0B = 0x98; //  - RXCIEn TXCIEn UDRIEn RXENn TNENn UCSZ2n RXB8n TXB8n
	// RXCIE 수신완료 Interrupt Enable Set
	// RXENn 수신기 Enable Set
	// TNENn 송신기 Enable Set	
	UCSR0C = 0x06; // - UMSELn UPMn1 UPMn0 USBSn UCSZn1 UCSZn0 UCPOLn
	// 비동기 모드
	// 패리티모드 사용 안함
	// UCSZn1 UCSZn0 -> 전송 데이터 비트 수 설정.-> 011 = 8비트. 즉 char단위
	// 클럭 극성 선택 X. 동기모드에서만 사용
	UBRR0H = 0;
	UBRR0L = 103;
	// bps 9600 선택
	
	sei();
	
    while (1) 
    {
    }
}

// 수신완료 Interrupt Service Routine
ISR(USART0_RX_vect){
	unsigned char ch;
	ch = UDR0; // 수신 버퍼에서 데이터 받음
	
	if(ch >= 'a' && ch <= 'z'){
		ch = ch - 'a' + 'A';
	}
	else if(ch >= 'A' && ch <= 'Z'){
		ch = ch - 'A' + 'a';
	}
	
	while((UCSR0A & 0x20) == 0x0){
		// 데이터 전송 완료 확인 Delay
	}
	UDR0 = ch;
	
	while((UCSR0A & 0x20)== 0x0){
		// 데이터 전송 완료 확인 Delay
	}
	UDR0 = '\n';
		
}
