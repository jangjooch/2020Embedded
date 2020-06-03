#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* solution(int prices[], size_t prices_len) {
	// return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
	int* answer = (int*)malloc(prices_len);
	printf("\n**************\n");
	printf("%d\n", prices_len);
	for (int i = 0; i < prices_len; i++) {
		printf("%d\t", prices[i]);
	}
	int state = 0;
	for (int i = 0; i < prices_len; i++) {
		for(int j = i + 1; j < prices_len; j++) {
			state++;
			if (prices[i] > prices[j]) {
				break;
			}			
		}
		answer[i] = state;
		state = 0;
	}

	printf("\n**************\n");
	for (int i = 0; i < prices_len; i++) {
		printf("%d\t", answer[i]);
	}
	printf("\n**************\n");
	return answer;
}


int main(void) {


	int prices[] = { 1, 2, 3, 2, 3 };
	solution(prices, sizeof(prices) / sizeof(int));

	system("pause");

	return 0;
}