
#include<stdio.h>

struct Product {
	int productNumber;
	char productName[5];
};

union Man {
	int age;
	unsigned char Name[4];
};

int main(void) {

	struct Product product01;
	product01.productNumber = 10;
	for (int i = 0; i < 5; i++) {
		product01.productName[i] = i;
	}
	printf("size of Product = %d\n", sizeof(product01));
	printf("Address of Product = %p\n", &product01);
	printf("Address of Product = %p\n", &(product01.productNumber));
	// int부터 선언되었기에 시작값과 동일하다
	printf("Address of Product = %p\n", &(product01.productName));
	printf("\n------------------------\n");
	printf("productNumber = %d\n", product01.productNumber);
	struct Product *p;
	p = &product01;
	// p가 product01의 주소값에 접근한 것이기 때문에
	p -> productNumber = 11;
	// 위처럼 해당하는 값을 바꾼다면
	// product01의 productNumber의 주소값에 있는 것이 바뀐것과 다를바없다.
	printf("productNumber = %d\n", p->productNumber);
	printf("productNumber = %d\n", product01.productNumber);
	printf("\n------------------------\n");

	union Man man;
	unsigned char *chp;
	chp = &man;

	man.age = (1<<12) | (1 << 7) | (1 << 3) | (1 << 1);
	
	printf("value of man = %d\n", man.age);
	printf("value of man = %d\n", man.Name[0]);
	printf("value of man = %d\n", man.Name[1]);
	printf("value of man = %d\n", man.Name[2]);
	printf("value of man = %d\n", man.Name[3]);
	printf("printing int age = %d\n", man.age);
	printf("printing address man = %p\n", &man);
	printf("printing address man.age = %p\n", &(man.age));
	printf("printing address man.Name = %p\n", &(man.Name));
	printf("printing sizeof man.Name = %d\n", sizeof(man.Name));
	// struct와 달리 union은 데이터를 하나의 배열로 저장하기때문에
	// 모든 주솟값의 시작은 동일하다.
	// 하나의 value와 char 배열을 주어
	// 데이터 전송 시 배열의 값을 보내는 형식으로 진행하도록 한다.
	
	// 만약 float 타입의 데이터를 전송한다고 할때
	//

	printf("\n------------------------\n");
	while (*chp != 0) {
		printf("value of man = %d\n", *chp++);
	}

	system("pause");
	return 0;
}