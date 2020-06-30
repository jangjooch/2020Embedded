/*
 * mp3_atmega128.c
 *
 * Created: 2020-06-26 오전 9:40:52
 * Author : abc
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned char data;
unsigned char txBuf[100];
unsigned char receivedData;
int txBuf_index = 0;
void SetUp();
void NextSong();
void PreviousSong();
void Pause();

ISR(USART1_RX_vect)
{
   unsigned char ch;
   ch = UDR1; // 수신
}
ISR(USART0_RX_vect)
{
   unsigned char ch;
   ch = UDR0; // 수신

   txBuf[txBuf_index] = ch;
   txBuf_index++;

   if(txBuf_index >= 5)
   {
      if(txBuf[0] == 0xFF && txBuf[1] == 0xFF && txBuf[3] == 0xFE && txBuf[4] == 0xFE )
      {
         receivedData = txBuf[2];
         SendCommand(receivedData,0,0);
      }
      txBuf_index = 0;
   }
   
}


int main(void)
{
   UCSR1A = 0x0;
   UCSR1B = 0x98; // RXCIE1 = 1,수신완료 인터럽트 인에이블 , 송수신 인에이블= 1
   UCSR1C = 0x06; // 비동기, 데이터 8비트 모드
   UBRR1H = 0;
   UBRR1L = 103; //16MHz , BAUD 9600

   UCSR0A = 0x0;
   UCSR0B = 0x98; // RXCIE1 = 1,수신완료 인터럽트 인에이블 , 송수신 인에이블= 1
   UCSR0C = 0x06; // 비동기, 데이터 8비트 모드
   UBRR0H = 0;
   UBRR0L = 103; //16MHz , BAUD 9600

   sei();
   //SendCommand(0x3F,0,0);
   //_delay_ms(100);
   SendCommand(0x09,0,2);
   _delay_ms(100);
   SendCommand(0x0D,0,0);
   _delay_ms(100);
    while (1) 
    {   
      
      _delay_ms(1000);
    }
}

void UART1_Putch(char data) // 송신
{
   while(!(UCSR1A & 0x20));
   UDR1 = data;
}
void UART0_Putch(char data) // 송신
{
   while(!(UCSR0A & 0x20));
   UDR0 = data;
}

void SendCommand(unsigned char cmd,unsigned char highdata,unsigned char lowdata)
{
   UART1_Putch(0x7E);
   UART1_Putch(0xFF);
   UART1_Putch(0x06);
   UART1_Putch(cmd);
   UART1_Putch(0x00); // feedback
   UART1_Putch(highdata);
   UART1_Putch(lowdata);
   int checksum = 0 - (0xFF + 0x06 + cmd + highdata + lowdata);
   UART1_Putch((char)(checksum >> 8));
   UART1_Putch(checksum & 0xFF);
   UART1_Putch(0xEF);

   _delay_ms(100);
}