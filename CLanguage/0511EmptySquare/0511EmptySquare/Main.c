#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long solution(int w, int h) {
	long long answer = 1;

	// 최대 공약수 찾기

	int smaller = 0;
	if (w > h)
		smaller = h;
	else
		smaller = w;
	int gain = 0;
	for (int i = 1; i <= smaller; i++) {
		if ((h%i == 0) && (w%i == 0)) {
			gain = i;
		}
	}
	// 적어도 1이 나오겠지

	// 최대공약수만큼 나누어 찾아내고
	int smallW = w / gain;
	int smallH = h / gain;

	int setting = 0;
	int mount = 0;
	if (smallW > smallH) {
		setting = smallW / smallH;
		if (smallW % smallH != 0) {
			setting++;
		}
		mount = setting * smallH;
	}
		
	else {
		setting = smallH / smallW;
		if (smallH % smallW != 0) {
			setting++;
		}
		mount = setting * smallW;
	}
	
	answer = (h * w) - (mount * gain);
	printf("%d\n", answer);

	return answer;
}

int main(void) {

	int x = 8;
	int y = 12;
	long long sum = solution(x, y);
	

	system("pause");

	return 0;
}