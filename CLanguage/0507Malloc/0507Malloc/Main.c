#include<stdlib.h>
#include<stdio.h>

int main(void) {

	int arr[5] = { 5,4, 3, 2, 1};
	int *pointArr;

	// int Ÿ�� ������ * 5 ��ŭ�� �޸𸮸� �Ҵ��Ѵ�.
	// �ش� ũ�⸸ŭ�� �޸𸮸� �������� �Ҵ��ϴ� malloc��
	// ����ϴ� ���̴�.
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
	// pointArr�� �Ҵ�Ǿ� �ִ� �޸� ����
	free(inputArr);
	
	

	system("pause");
	return 0;
}