/*
 * 0728_Multi_Test01.c
 *
 * Created: 2020-07-28 오후 2:15:52
 * Author : 301-PC-21
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>


volatile int mode = 0;
// 0 = ARM1
// 1 = ARM2
// 2 = CAR1
// 3 = CAR2
// 4 = Non Active

volatile unsigned long idx = 0;

volatile unsigned long timer[4] = {0, 0, 0, 0};
volatile unsigned long pwmValue[4] = {0, 0, 0, 0};
// value 0, 1, mode 0, 1

volatile long setAngel[4] = {90, 90, 90, 90};
volatile long motor[2] = {0, 0};
volatile char CW[4] = {0, 0, 0, 0};
volatile char Break[4] = {0, 0, 0, 0};
	
int direction = 0;
int maxIdx = 0;

long mapping(long x,long in_min,long in_max, long out_min, long out_max);
		
int main(void)
{
    /* Replace with your application code */
	// 메뉴 입력
	// 상|중|하  상|중|하
	// 상 -> ARM // 상 하
	// 하 -> Car // 상 하


	
	TCCR1A = 0xAA;
	// COM1A1 COM1A0 COM1B1 COM1B0 COM1C1 COM1C0 WGM11 WGM10
	// 1010 1010 -> ICR 만날시 Set
	// WGM11 WGM10 : 1 0 -> 14번모드 1 1 1 0 을 위함
	TCCR1B = 0x1A;
	// ICNC1 ICES1 - WGM13 WGM12 CS12 CS11 CS10
	// WGM13 WGM12 : 1 1 -> 14번모드 1 1 1 0 을 위함
	// CS12 CS11 CS10 : 분주율 8 -> 0 1 0 을 위함
	TCCR1C = 0x00;
	ICR1 = 40000;
	// TOP 설정
	// 분주 = 1/16 * 8 * 40000 = 20000nanoSec = 20ms
	// Duty Cycle 설정
	//DDRB = 0xF0;
	// OCR1A, B, C PB5, 6, 7 출력
	
	TCCR3A = 0x82;
	TCCR3B = 0x1A;
	TCCR3C = 0x00;
	ICR3 = 40000;
	
	DDRE = 0x0F;
	// OC3A 출력  -> PE3
	// INT 4 입력 -> PE4
	DDRC = 0xF0;
	
	// pwm 입력측정을 위한 외부 Interrupt
	EICRA = 0x55;
	// ISC31 ISC30 ISC21 ISC20 | ISC11 ISC10 ISC01 ISC00
	// INT 3, 2, 1, 0
	// Change 설정 Change -> 0 1
	EIMSK = 0x0F;
	// INT 3, 2, 1, 0 Enable

	
	TCCR0 = 0x6F;
	// - FOC0 WGM00 COM01 COM00 WGM01 CS02 CS01 CS00
	//    0    1     1     0      1     1    1    1
	// CTC 출력 x
	// WGM00 01 1 1 : Fast PWM mode
	// COM01 00 1 0 : CTC Clear
	// SC02 01 00 : 1024  분주율
	// 1/16 * 1024 * 255 = 160000 = 16ms
	OCR0 = 0; // 이것으로 Duty Cycle 조정
	// 0 ~ 255
	// Interrupt 는 없으니 TIMSK 설정은 하지 않는다.
	DDRB |= 0x10; // PB4 OC0 출력
	
	DDRB = 0xF0;
	// idx 측정용
	TCCR2 = 0b00000001;
	TIMSK |= 0x40;
	TCNT2 = 0;
	
	
	sei();
	
	
    while (1) 
    {
		
		// 상 상 ARM 0
		if( (pwmValue[2] < 70) && (pwmValue[3] < 70) ){
			mode = 0;
			ArmServo(0);
		}
		else if( (pwmValue[2] < 70) && (pwmValue[3] > 90) ){
			// 상 하 ARM 1
			mode = 1;
			ArmServo(2);
		}
		else if( (pwmValue[2] > 90) && (pwmValue[3] < 70) ){
			// 하 상 CAR 0
			// 직진 좌우
			mode = 2;
			DCMotor(0);
		}
		else if( (pwmValue[2] > 90) && (pwmValue[3] > 90) ){
			// 하 하 CAR 1
			// 직진 스로틀
			mode = 3;
			DCMotor(1);
		}
		else{
			mode = 4;
		}
		
		
		
		OCR1A = mapping(setAngel[0] , 0, 180, 1000, 5000);
		OCR1B = mapping(setAngel[1] , 0, 180, 1000, 5000);
		OCR1C = mapping(setAngel[2] , 0, 180, 1000, 5000);
		OCR3A = mapping(setAngel[3], 0, 180, 1000, 5000);
    }
}


// value0
ISR(INT0_vect){
	INT_Method(0);
}

// value1
ISR(INT1_vect){
	INT_Method(1);
}

// mode0
ISR(INT2_vect){
	INT_Method(2);
}

//mode1
ISR(INT3_vect){
	INT_Method(3);
}

ISR(TIMER2_OVF_vect){
	idx = idx + 1;
	TCNT2 = 0;
}

void DCMotor(int a){
	
	long pwmGet = 0;
	pwmGet = pwmValue[0] - 75;
	if(pwmGet < 0){
		pwmGet = -pwmGet;
	}
	
	if(pwmGet < 3){
		OCR0 = 80;
	}
	else{
		OCR0 = mapping(pwmGet, 0, 20, 120, 253);
		if(direction){
			// CWW SET
		}
		else{
			// CW CLEAR
		}
	}
	
	// maxValue = motor[maxIdx]
	// 방향 = direction 0 정방/1역방
	
	unsigned long past = idx;
	while(idx - past < 500){
		;
	}
}

void ArmServo(int a){
	if(pwmValue[0] > 400000){
		
	}
	else{
		if(pwmValue[0] < 70){
			setAngel[a] = setAngel[a] - 1;
		}
		else if(pwmValue[0] > 90){
			setAngel[a] = setAngel[a] + 1;
		}
		if(setAngel[a] > 180){
			setAngel[a] = 120;
		}
		else if(setAngel[a] < 0){
			setAngel[a] = 20;
		}
	}
	
	if(pwmValue[1] > 400000){
		
	}
	else{
		if(pwmValue[1] < 70){
			setAngel[a+1] = setAngel[a+1] - 1;
		}
		else if(pwmValue[1] > 90){
			setAngel[a+1] = setAngel[a+1] + 1;
		}
		if(setAngel[a + 1] > 180){
			setAngel[a + 1] = 180;
		}
		else if(setAngel[a + 1] < 0){
			setAngel[a + 1] = 0;
		}
	}
	unsigned long past = idx;
	while(idx - past < 500){
		;
	}
}

void INT_Method(int a){
	if( (PIND & (1 << a) ) ){
		timer[a] = idx;
	}
	else{
		PORTC = 0x00;
		if(timer[a] != 0){
			pwmValue[a] = idx - timer[a];
		}
	}
}

long mapping(long x,long in_min,long in_max, long out_min, long out_max)
{
	if(x > in_max){
		x = in_max;
	}
	else if(x < in_min){
		x = in_min;
	}
	long result = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
	return result;
}