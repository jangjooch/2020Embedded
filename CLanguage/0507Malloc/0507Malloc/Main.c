#include<stdlib.h>
#include<stdio.h>

int main(void) {

	int arr[5] = { 5,4, 3, 2, 1};
	int *pointArr;

	// int 타입 사이즈 * 5 만큼의 메모리를 할당한다.
	// 해당 크기만큼의 메모리를 동적으로 할당하는 malloc을
	// 사용하는 것이다.
	pointArr = (int *)malloc(sizeof(int) * 5);

	if (pointArr == NULL) {
		printf("malloc Error");
	}

	for (int i = 0; i < 5; i++) {
		pointArr[i] = arr[i];
	}

	for (int i = 0; i < 5; i++) {
		printf("%d : %d \n", i, pointArr[i]);
	}

	int num;
	int *inputArr;
	int average = 0;
	printf("howMany input? : ");
	scanf_s("%d", &num);

	//inputArr = (int *)malloc(sizeof(int)*num);
	inputArr = (int *)malloc(sizeof(int) * num);
	if (inputArr == NULL) {
		printf("inputArr Error");		
	}

	for (int i = 0; i < num; i++) {
		printf("input Score : ");
		scanf_s("%d", &inputArr[i]);
	}
	printf("\ntesting\n");

	for (int i = 0; i < num; i++) {
		printf("%d : %d \n", i, inputArr[i]);
	}

	free(pointArr);
	// pointArr에 할당되어 있는 메모리 해제
	free(inputArr);
	
	

	system("pause");
	return 0;
}