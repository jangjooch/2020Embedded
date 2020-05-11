#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* solution(int heights[], size_t heights_len) {
	// return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.

	int* answer = (int*)malloc(heights_len);

	for (int i = 0; i < heights_len; i++) {
		printf("%d\t", heights[i]);
	}
	answer[0] = 0;
	
	printf("\n**************\n");
	for (int i = heights_len - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (heights[j] > heights[i]) {
				answer[i] = j + 1;
				break;
			}
			if (j == 0) {
				answer[i] = 0;
			}
			
		}
	}
	
	
	for (int i = 0; i < heights_len; i++) {
		printf("%d\t", answer[i]);
	}
	
	
	

	
	printf("\n**************\n");
	

	return answer;
}


int main(void) {

	int arr01[] = { 1,5,3,6,7,6,5 };
	
	solution(arr01, sizeof(arr01) / sizeof(int));

	system("pause");

	return 0;
}