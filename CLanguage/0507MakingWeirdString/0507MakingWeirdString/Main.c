#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
	// return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.

	
	char *copy = (char*)malloc(strlen(s));;
	copy = strcpy(copy, s);
	// 문자열 복사

	char* answer = (char*)malloc(strlen(s));
	// 문자열의 길이는 strlen 을 통하여 알아낼 수 있다.

	int state[26] = { 0, };
	// 알파벳에 따라 내용을 저장할 것이다.

	int stat[26] = { 0, };

	printf("%s\n", copy);
	printf("%c\n", copy[4]);
	printf("%d\n", copy[4]);
	// 아스키 코드 a : 97 ~ z : 122
	for (int i = 0; i < strlen(s); i++) {
		if (copy[i] == ' ') {
			// 공백일 경우 넘어가도록 한다.
		}
		else {
			// 0이 아닐 경우
			state[copy[i]-97]++;
			// copy[i]-97 해당 아스키 코드 값에서 기준값인 a의 값을 제하여 ++ 을 진행한다.
		}
	}
	// 확인
	for (int i = 0; i < 26; i++) {
		printf("%c : %d\n", i + 97, state[i]);
	}
	for (int i = 0; i < strlen(copy); i++) {
		if (copy[i] == ' ') {

		}
		else {
			printf("i = %d \t copy = %c \t before stat = %d\n", i, copy[i], stat[copy[i]-97]);
			if (stat[copy[i] - 97] == 0) {
				// 홀수개인 경우 넘어간다.
				stat[copy[i] - 97]++;
			}
			else {
				stat[copy[i] - 97] = 0;
				// 바꾸어 준다음에는 0으로 되돌린다.

				// 짝수개인 경우 -32를 하여 대문자로 바꾸어 준다.
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


