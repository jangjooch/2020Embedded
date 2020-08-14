

#include <Adafruit_PN532.h>

#include <Wire.h>
#include <SPI.h>



#define PN532_SCK  9
#define PN532_MOSI 10
#define PN532_SS   8
#define PN532_MISO 11

#define PN532_IRQ   44
#define PN532_RESET 43  // Not connected by default on the NFC Shield

Adafruit_PN532 nfc(PN532_SCK, PN532_MISO, PN532_MOSI, PN532_SS);

unsigned long doorStart = 0;
unsigned char doorState = 0;

unsigned long buzzerStart = 0;
unsigned char buzzerState = 0;

unsigned long past = 0;
unsigned long idx = 0;

void setup(void) {
  
  UCSR0A = 0x00;
  UCSR0B = 0x18;
  // 수신 interrupt Enable
  // R/TX Enable
  UCSR0C = 0x06;
  UBRR0H = 0;
  UBRR0L = 103;

  TCCR3A = 0x82;
  // COMA1 COMA0 : 1 0 -> ICR1을 만나면 Clear
  // WGM11 WGM10 : 1 0 -> 14번모드 1 1 1 0 을 위함
  TCCR3B = 0x1A;
  // WGM13 WGM12 : 1 1 -> 14번모드 1 1 1 0 을 위함
  // CS12 CS11 CS10 : 분주율 8 -> 0 1 0 을 위함
  TCCR3C = 0x00;
  // PWM모드에서는 출력할 것이 없다.
  ICR3 = 40000;
  OCR3A = 2000;
  // TOP 설정
  // 분주 = 1/16 * 8 * 40000 = 20000nanoSec = 20ms
  // Duty Cycle 설정
  DDRE |= 0x08;
  // OCR3A
  
  DDRA = 0xF0;
  // Buzzer
  //PORTA = 0xF0;

  DDRD = 0xF0;

  // Button Int0
  EICRA = 0b00001010;
  EIMSK = 0x03;
  PORTD = 0x03;

  // 8bit Timer
  TCCR2 = 0x05;
  TCNT2 = 0;
  TIMSK = 0x40;
  
  SREG |= 0x80;
  
  nfc.begin();
  
  // configure board to read RFID tags
  nfc.SAMConfig();
  
}

void loop(void) {
  uint8_t success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
  uint8_t uidLength;                        // Length of the UID (4 or 7 bytes depending on ISO14443A card type)
    
  // Wait for an NTAG203 card.  When one is found 'uid' will be populated with
  // the UID, and uidLength will indicate the size of the UUID (normally 7)
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);
  if (success) {
    // Display some basic information about the card
    UART_Putchar(0xFF);
    UART_Putchar(uidLength & 0xFF);
    for(int i = 0; i < uidLength ; i++){
      UART_Putchar(uid[i]);
    }
  }
}

ISR(TIMER2_OVF_vect){
  idx++;  
  if(doorState){
    if( (idx - doorStart) > 300){
      doorStart = 0;
      doorState = 0;
      idx = 0;
      OCR3A = 1000;
    }
  }
  if(buzzerState != 0){
    if( idx - buzzerStart < 100){
      PORTA = 0x80;
    }
    else if(idx - buzzerStart < 150){
      PORTA = 0x00;
    }
    else{
      buzzerStart = idx;
      buzzerState --;
    }
  }
  else{
    buzzerStart = 0;
    PORTA = 0x00;
  }

  if(UCSR0A & 0x80){
    // 데이터가 전송되었다면
    //PORTC = 0xF0;
    unsigned char data = UDR0;
    if(data == 0x01){
      Door_Open();
      BuzzerActivate(1);
    }
    else{
      BuzzerActivate(3);
    }
  }
}


ISR(USART_RX_vect){

}

ISR(INT0_vect){
  Door_Open();
}

void UART_Putchar(unsigned char data){
  while((UCSR0A & 0x20) == 0x0){    
    ;
  }
  UDR0 = data;
  //데이터 씀
}

void Door_Open(){
  doorStart = idx;
  OCR3A = 5000;
  doorState = 1;
}

void BuzzerActivate(unsigned char a){
  buzzerStart = idx;
  buzzerState = a;
}
