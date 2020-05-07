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

	// 알파벳에 따라 내용을 저장할 것이다.

	int stat[26] = { 0, };
	int state = 0;
	// 아스키 코드
	// a : 97 ~ z : 122
	// A : 65 ~ 90
	
	for (int i = 0; i < strlen(copy); i++) {
		if (copy[i] == ' ') {
			//printf("Reset\n");
			state = 0;
			// 공백 시 state 초기화
		}
		else {
			if (state % 2 == 0) {
				//printf("Happened  i = %d \t state = %d \n", i, state);
				if (copy[i] >= 97 && copy[i] < 122) {
					copy[i] = copy[i] - 32;
					// 짝수번째 일 경우 대문자로 변경
				}
				
			}
			else {
				// 홀수번쨰 일 경우 소문자
				if (copy[i] >= 65 && copy[i] < 90) {
					copy[i] = copy[i] + 32;
					// 짝수번째 일 경우 대문자로 변경
				}
			}
			state++;// 공백 나오기 전까지 증가
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


