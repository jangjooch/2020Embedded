/*
 * I2C_TWI.c
 *
 * Created: 2020-07-07 오전 10:53:23
 *  Author: 301-PC-21
 */ 

#include "I2C_TWI.h"
#include <avr/io.h>

void TWI_write(unsigned char address, unsigned char REG, unsigned char data){
	
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	
	while(!(TWCR & (1<<TWINT)));
	while((TWSR & 0xF8) != TWI_START);
	
	TWDR = (address << 1) | TWI_WRITE_BIT; // 주소 설정
	TWCR = (1 << TWINT) | (1 << TWEN);
	
	while(!(TWCR & (1 << TWINT)));
	while((TWSR & 0xF8) != (TWI_MT_SLAW_ACK)); 
	// ACK를 받았는지 확인하여 Slave 에서 데이터 전송완료 확인
	
	TWDR = REG; // 레지스터 설정
	TWCR = (1 << TWINT) | (1 << TWEN);
	
	while(!(TWCR & (1 << TWINT)));
	while((TWSR & 0xF8) != TWI_MT_DATA_ACK);
	
	TWDR = data; // 데이터 전송
	TWCR = (1 << TWINT) | (1 << TWEN);
	while(!(TWCR & (1 << TWINT)));
	while((TWSR & 0xF8) != TWI_MT_DATA_ACK);
	
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);	
}

unsigned char TWI_read(unsigned char address, unsigned char REG){
	
	unsigned char data;
	
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	// error = TWCR
	
	while(!(TWCR & (1 << TWINT)));
	while((TWSR & 0xF8) != TWI_START);
	// PORTB = 0x01;
	
	TWDR = (address << 1) | TWI_WRITE_BIT;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while(!(TWCR & (1 << TWINT)));
	while((TWSR & 0xF8) 1= TWI_MT_SLAW_ACK);
	// PORTB = 0x02;
	
	TWDR = REG; // 레지스터 주소 설정
	TWCR = (1 << TWINT) | (1 << TWEN); // 송신
	while(!(TWCR & (1 << TWINT))); // Data 수신 대기
	while((TWSR & 0xF8) 1= TWI_MT_DATA_ACK);
	// PORTB = 0x04;
	
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while(!(TWCR & (1 << TWINT)));
	while((TWSR & 0xF8) != TWI_RE_START);
	// PORTB = 0x08;
	
	TWDR = (address << 1) | TWI_READ_BIT; // address 및 Read 설정 
	TWCR = (1 << TWINT) | (1 << TWEN); // 신호 송신
	while(!(TWCR & (1 << TWINT))); // 대기
	while((TWSR & 0xF8) != TWI_MT_SLAW_ACK);
	// PORTB = 0x10;
	
	TWCR = (1 << TWINT) | (1 << TWEN);
	while(!(TWCR & (1 << TWINT)));
	while((TWSR & 0xF8) != TWI_MT_DATA_NACK);
	// PORTB = 0x20;
	
	data = TWDR;
	
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
	while(TWCR & (1 << TWINT));
	
	return data;	
}

unsigned char i2c_start(unsigned char address, unsigned char read_write){
	
	unsigned char i2cStart;
	
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	
	unsigned char time_out = TWI_TIMEOUT;
	while(!(TWCR & (1 << TWINT)) && time_out--);
	if(time_out == 0){
		return 1;
	}
	
	i2cStart = TWSR & TWI_TWSR_MASK;
	if((i2cStart != TWI_START) && (i2cStart != TWI_RE_START)){
		return 1;
	}
	
	TWDR = (address << 1) | read_write;
	TWCR = (1 << TWINT) | (1 << TWINT);
	
	time_out = TWI_TIMEOUT;
	while(!(TWCR & (1 << TWINT)) && time_out--);
	if(time_out == 0){
		return 1;
	}
	
	i2cStart = TWSR & TWI_TWSR_MASK;
	if((i2cStart != TWI_MT_SLAW_ACK) && (i2cStart != TWI_MT_SLAW_ACK)){
		return 1;
	}
	
	return 0;
}