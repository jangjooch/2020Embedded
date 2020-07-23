/*
 * I2C_TWI.h
 *
 * Created: 2020-07-07 오전 10:45:20
 *  Author: 301-PC-21
 */ 


#ifndef I2C_TWI_H_
#define I2C_TWI_H_

#define TWI_READ_BIT 1
#define TWI_WRITE_BIT 0

#define TWI_TIMEOUT 0XFF

#define SCL_CLOCK 400000UL

#define TWI_TWSR_MASK 0XF8
#define TWI_START 0X08
#define TWI_RE_START 0X10
#define TWI_MT_SLAW_ACK 0X18
#define TWI_MT_SLAW_NACK 0X20
#define TWI_MT_DATA_ACK 0X28
#define TWI_MT_DATA_NACK 0X58
#define TWI_MT_SLAR_ACK 0X40
#define TWI_MT_SLAR_NACK 0X48

void TWI_write(unsigned char address, unsigned char REG, unsigned char data);
unsigned char TWI_read(unsigned char address, unsigned char REG);
unsigned char i2c_start(unsigned char address, unsigned char read_write);
unsigned char i2c_start_wait(unsigned char address, unsigned char read_write);
unsigned char i2c_stop();
unsigned char i2c_write(unsigned char data);
unsigned char i2c_readACK();
unsigned char i2c_readNACK();



#endif /* I2C_TWI_H_ */