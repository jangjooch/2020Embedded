/*
 * UART_Beginning01.c
 *
 * Created: 2020-06-24 오전 10:12:47
 * Author : 301-PC-21
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

int main(void)
{
	
	
	
	
	UCSR0A = 0x00; //  - RXCn TXCn UDREn FEn | DORn UPEn U2Xn MPCMn
	// 비동기 방식
	// 멀티프로세서 통신모드 Enable -> 0이 Enable임
	UCSR0B = 0x08; //  - RXCIEn TXCIEn UDRIEn RXENn TNENn UCSZ2n RXB8n TXB8n
	// TNENn 송신기 Enable Set
	UCSR0C = 0x06; // - UMSELn UPMn1 UPMn0 USBSn UCSZn1 UCSZn0 UCPOLn
	// 비동기 모드
	// 패리티모드 사용 안함
	// UCSZn1 UCSZn0 -> 전송 데이터 비트 수 설정.-> 011 = 8비트. 즉 char단위
	// 클럭 극성 선택 X. 동기모드에서만 사용
	UBRR0H = 0;
	UBRR0L = 103;
	// bps 9600 선택
	
	
	char dataString[] = "This is UART0 Test Program\r\n";
	char *dataPtr;
		
    /* Replace with your application code */
    while (1) 
    {
		dataPtr = dataString;
		// dataPtr포인터를 dataString 주소로 설정
		while(*dataPtr != 0){
			UART_Putchar(*dataPtr++);
			//*dataPtr++;			
		}
		_delay_ms(1000);
		
    }
}

void UART_Putchar(char data){
	while((UCSR0A & 0x20) == 0x0){
		// UDRE0 이 1이 될때가지 대기		
		// 즉 데이터 전송 버퍼가 비일때까지 대기
		// 전송버퍼가 비인다면 1로 Set됨
		;
	}
	UDR0 = data;
	//데이터 씀
}

