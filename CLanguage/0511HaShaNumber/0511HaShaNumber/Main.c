#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


bool solution(int x) {
	bool answer = true;

	int copy = x;

	int sum = 0;

	while (copy > 0) {
		sum = sum + (copy % 10);
		copy = copy / 10;
	}
	
	if (x%sum == 0) {

	}
	else {
		answer = false;
	}

	return answer;
}

int main(void) {

	solution(123);

	system("pause");
	return 0;
}