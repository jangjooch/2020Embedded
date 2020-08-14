#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>


int main() {

	char input = ' ';
	char past = ' ';

	while (1) {

		printf("input Num : ");
		scanf("%c", &input);		
		getchar(); // 버퍼 클리어
		if ((input == '1') && (past == '0')) {
			printf("Check\n");
		}
		if (input == '0' || input == '1') {
			past = input;
		}
		else {
			printf("Wrong Input\n");
		}
			
	}




	system("pause");
	return 0;
}