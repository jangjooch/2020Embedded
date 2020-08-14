#define _CRT_SECURE_NO_WARNINGS
#define _BV(bit) (1 << (bit))
#define sbi(x,y) x |= _BV(y) //set bit - using bitwise OR operator
#define cbi(x,y) x &= ~(_BV(y)) //clear bit - using bitwise AND operator
#define tbi(x,y) x ^= _BV(y) //toggle bit - using bitwise XOR operator

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	int num01 = 0xA;
	int num02 = 0x0F;
	printf("%x\n", num01 & num02);
	printf("%x\n", num01 && num02);
	printf("%x\n", num01 || num02);
	printf("%x\n", ~num01);
	// ~ 이 비트 연산자 not을 하는 것이기에 보수를 만들어준다.
	printf("%x\n", !(num01));
	// !는 논리연산자 not을 하는 것이기에 True라면 False, 즉 0으로 바꾸어 준다.
	printf("\n");
	int num03 = 0xAA;

	// 위 define을 통해 간단한 함수를 만들어 사용할 수 있다.
	// 전부 call by reference이기때문에 값이 변함을 확인할 수 있다.
	// 두번째 인자 port 즉 위치 정보를 전송해 해당하는 값을 가져와
	// 1과의 연산을 통해 set, clear, toggle이 될 수 있도록 한다.
	unsigned char port;
	port = 0xAA;
	printf("%x\n", sbi(port, 2));

	port = 0xAA;
	printf("%x\n", cbi(port, 1));

	port = 0xAA;
	printf("%x\n", tbi(port, 2));

	system("pause");

	return 0;
}