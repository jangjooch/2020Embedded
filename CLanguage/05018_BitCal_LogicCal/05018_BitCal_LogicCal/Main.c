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
	// ~ �� ��Ʈ ������ not�� �ϴ� ���̱⿡ ������ ������ش�.
	printf("%x\n", !(num01));
	// !�� �������� not�� �ϴ� ���̱⿡ True��� False, �� 0���� �ٲپ� �ش�.
	printf("\n");
	int num03 = 0xAA;

	// �� define�� ���� ������ �Լ��� ����� ����� �� �ִ�.
	// ���� call by reference�̱⶧���� ���� ������ Ȯ���� �� �ִ�.
	// �ι�° ���� port �� ��ġ ������ ������ �ش��ϴ� ���� ������
	// 1���� ������ ���� set, clear, toggle�� �� �� �ֵ��� �Ѵ�.
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