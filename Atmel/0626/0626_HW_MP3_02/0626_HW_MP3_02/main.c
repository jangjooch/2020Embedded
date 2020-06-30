/*
 * 0626_HW_MP3_01.c
 *
 * Created: 2020-06-26 오전 10:12:16
 * Author : 301-PC-21
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#define CMD_Next 0x01
#define CMD_Previous 0x02
#define CMD_Increase_Vol 0x04
#define CMD_Decrease_Vol 0x05
#define CMD_Play_Back 0x0D
#define CMD_Pause 0x0E
#define CMD_Start 0x09


int main(void)
{
	UCSR0A = 0x00;	
	UCSR0B = 0x98;	
	UCSR0C = 0x06;	
	UBRR0H = 0;
	UBRR0L = 103; //buad Rate
	
	UCSR1A = 0x00;
	// RXCn TXCn UDREn FEn | DORn UPEn U2Xn MPCMn
	// 비동기 방식
	// 멀티프로세서 통신모드 Enable -> 0이 Enable임
	UCSR1B = 0x08;
	// RXCIEn TXCIEn UDRIEn RXENn | TNENn UCSZ2n RXB8n TXB8n		
	// TNENn 송신기 Enable Set
	UCSR1C = 0x06;
	// UMSELn UPMn1 UPMn0 USBSn | UCSZn1 UCSZn0 UCPOLn
	// 비동기 모드
	// 패리티모드 사용 안함
	// UCSZn1 UCSZn0 -> 전송 데이터 비트 수 설정.-> 011 = 8비트. 즉 char단위
	// 클럭 극성 선택 X. 동기모드에서만 사용
	UBRR1H = 0;
	UBRR1L = 103; //buad Rate 
	
	sei();
	
	_delay_ms(1000);
	//dataSend(0x3F,0);
	_delay_ms(100);	
	dataSend(0x09,2);
	_delay_ms(100);	
	dataSend(0x0D,0);
	_delay_ms(100);
	dataSend(0x06,20);
	_delay_ms(100);	
	
    while (1) 
    {		
		
		
    }
}
void UART1_Putchar(char data){
	while((UCSR1A & 0x20) == 0x0){
		// UDRE0 이 1이 될때가지 대기
		// 즉 데이터 전송 버퍼가 비일때까지 대기
		// 전송버퍼가 비인다면 1로 Set 됨
		;
	}
	UDR1 = data;
	//데이터 씀
}

void UART0_Putchar(char data){
	while((UCSR0A & 0x20) == 0x0){
		// UDRE0 이 1이 될때가지 대기
		// 즉 데이터 전송 버퍼가 비일때까지 대기
		// 전송버퍼가 비인다면 1로 Set 됨
		;
	}
	UDR0 = data;
	//데이터 씀
}

ISR(USART0_RX_vect){
	char data;
	data = UDR0;
	
	dataSend(data, 0);
	
	_delay_ms(1000);
}

void dataSend(char cmdget, int param){
	unsigned char cmd[10];
	unsigned int paraminit = param;
	
	cmd[0] = 0x7E;
	cmd[1] = 0xFF;
	cmd[2] = 0x06;
	
	cmd[3] = cmdget;
	cmd[4] = 0x00;
	cmd[5] = ((unsigned char)(paraminit>>8));
	cmd[6] = ((unsigned char)(paraminit & 0x00FF));
	unsigned int checkSum =  0 - (0xFF + 0x06 + cmdget + cmd[5] + cmd[6]);
	cmd[7] = ((unsigned char)(checkSum >> 8));
	cmd[8] = ((unsigned char)(checkSum & 0x00FF));
	cmd[9] = 0xEF;
	
	for(int i = 0 ; i < 10 ; i++){
		UART1_Putchar(cmd[i]);
	}
}
