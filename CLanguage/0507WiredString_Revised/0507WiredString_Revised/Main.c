#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char* solution(const char* s) {
	// return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.


	char *copy = (char*)malloc(strlen(s));;
	copy = strcpy(copy, s);
	// ���ڿ� ����

	// ���ĺ��� ���� ������ ������ ���̴�.

	int stat[26] = { 0, };
	int state = 0;
	// �ƽ�Ű �ڵ�
	// a : 97 ~ z : 122
	// A : 65 ~ 90
	
	for (int i = 0; i < strlen(copy); i++) {
		if (copy[i] == ' ') {
			//printf("Reset\n");
			state = 0;
			// ���� �� state �ʱ�ȭ
		}
		else {
			if (state % 2 == 0) {
				//printf("Happened  i = %d \t state = %d \n", i, state);
				if (copy[i] >= 97 && copy[i] < 122) {
					copy[i] = copy[i] - 32;
					// ¦����° �� ��� �빮�ڷ� ����
				}
				
			}
			else {
				// Ȧ������ �� ��� �ҹ���
				if (copy[i] >= 65 && copy[i] < 90) {
					copy[i] = copy[i] + 32;
					// ¦����° �� ��� �빮�ڷ� ����
				}
			}
			state++;// ���� ������ ������ ����
		}
	}
	//printf("%s\n", copy);

	//printf("%s\n", answer);

	return copy;
}

int main(void) {

	const char* s = "try hello world";

	char *answer = solution(s);

	system("pause");

	return 0;
}


