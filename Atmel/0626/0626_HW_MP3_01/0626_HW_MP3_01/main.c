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

union cmd{
	char comands[10];
};

int returnChecksum(char _ver, char _len, char _cmd, char _param1, char _param2);


int main(void)
{
	UCSR0A = 0x00;	
	UCSR0B = 0x08;	
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
	
	union cmd start;
	start.comands[0] = 0x7E;
	// start
	start.comands[1] = 0xFF;
	// version
	start.comands[2] = 0x06;
	// Len
	start.comands[3] = 0x09;
	// CMD
	start.comands[4] = 0x00;
	// Feedback
	start.comands[5] = 0x00;
	// parameter1
	start.comands[6] = 0x02; // start Param U/TF/AUX/SLEEP/FLASH
	// parameter2
	int start_check = returnChecksum(start.comands[1], start.comands[2], start.comands[3], start.comands[5], start.comands[6]);
	int test = 0 - (0xFF + 0x06 + 0x09 + 0x01);
	//start.comands[7] = (char)(start_check >>8);
	start.comands[7] = ((char)(test >> 8));
	// checksum H
	//start.comands[8] = (char)(start_check & 0xFF);
	start.comands[8] = ((char)(test & 0x00FF));
	// checksum L
	start.comands[9] = 0xEF;
	// END
	
	union cmd doit;
	doit.comands[0] = 0x7E;
	// start
	doit.comands[1] = 0xFF;
	// version
	doit.comands[2] = 0x06;
	// Len
	doit.comands[3] = 0x01;
	// CMD
	doit.comands[4] = 0x00;
	// Feedback
	doit.comands[5] = 0x00;
	// parameter1
	doit.comands[6] = 0x00; 
	// parameter2
	int doit_check = returnChecksum(doit.comands[1], doit.comands[2], doit.comands[3], doit.comands[5], doit.comands[6]);
	test = 0 - (0xFF + 0x06 + 0x01);
	doit.comands[7] = ((char)(test >> 8));
	// checksum H
	doit.comands[8] = ((char)(test & 0x00FF));
	// checksum L
	doit.comands[9] = 0xEF;
	// END
	
	//char *p;
	//p = &start;
	
	_delay_ms(100);
	
	
	
	/*
	while(p != 0){
		UART1_Putchar(*p++);
	}
	*/
	
    /* Replace with your application code */
	for(int i = 0 ; i < 10 ; i ++){
		UART1_Putchar(start.comands[i]);
	}
	_delay_ms(1000);
	for(int i = 0 ; i < 10 ; i ++){
		UART1_Putchar(doit.comands[i]);
	}
	
    while (1) 
    {		
		
		for(int i = 0 ; i < 10 ; i ++){
			UART0_Putchar(doit.comands[i]);
		}
		_delay_ms(1000);
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

int returnChecksum(char _ver, char _len, char _cmd, char _param1, char _param2){
	int result = 0 - (_ver + _len + _cmd + _param1 + _param2);
	return result;
}