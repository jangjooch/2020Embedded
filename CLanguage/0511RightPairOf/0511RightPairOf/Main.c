#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool solution(const char* s) {

	bool answer = true;

	char *copy = (char*)malloc(strlen(s));;
	copy = strcpy(copy, s);
	// s의 길이만큼의 malloc을 생성하고
	// s의 내용을 copy에 복사한다.

	//printf("%s\n", copy);

	//printf("%c\n", copy[2]);
	
	int stack = 0;

	for (int i = 0; i < strlen(copy); i++) {
		if (copy[i] == '(') {
			stack++;
		}
		else {
			stack--;
		}
		if (stack < 0) {
			answer = false;
			break;
		}
	}

	if (stack != 0) {
		answer = false;
	}

	return answer;
}

int main(void) {

	const char* s = "))((";

	bool thing = solution(s);

	system("pause");

	return 0;
}


