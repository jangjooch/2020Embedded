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

	char* answer = (char*)malloc(strlen(s));
	// ���ڿ��� ���̴� strlen �� ���Ͽ� �˾Ƴ� �� �ִ�.

	int state[26] = { 0, };
	// ���ĺ��� ���� ������ ������ ���̴�.

	int stat[26] = { 0, };

	printf("%s\n", copy);
	printf("%c\n", copy[4]);
	printf("%d\n", copy[4]);
	// �ƽ�Ű �ڵ� a : 97 ~ z : 122
	for (int i = 0; i < strlen(s); i++) {
		if (copy[i] == ' ') {
			// ������ ��� �Ѿ���� �Ѵ�.
		}
		else {
			// 0�� �ƴ� ���
			state[copy[i]-97]++;
			// copy[i]-97 �ش� �ƽ�Ű �ڵ� ������ ���ذ��� a�� ���� ���Ͽ� ++ �� �����Ѵ�.
		}
	}
	// Ȯ��
	for (int i = 0; i < 26; i++) {
		printf("%c : %d\n", i + 97, state[i]);
	}
	for (int i = 0; i < strlen(copy); i++) {
		if (copy[i] == ' ') {

		}
		else {
			printf("i = %d \t copy = %c \t before stat = %d\n", i, copy[i], stat[copy[i]-97]);
			if (stat[copy[i] - 97] == 0) {
				// Ȧ������ ��� �Ѿ��.
				stat[copy[i] - 97]++;
			}
			else {
				stat[copy[i] - 97] = 0;
				// �ٲپ� �ش������� 0���� �ǵ�����.

				// ¦������ ��� -32�� �Ͽ� �빮�ڷ� �ٲپ� �ش�.
				copy[i] = copy[i] - 32;
				
			}
			printf("after stat = %d\n", stat[copy[i] - 97]);
		}
	}
	printf("%s", copy);

	//printf("%s\n", answer);

	return answer;
}

int main(void) {

	const char* s = "aaabbcccc";

	char *answer = solution(s);
	
	system("pause");

	return 0;
}


