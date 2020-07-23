/*
 * 0706_Atmel_Debug01.c
 *
 * Created: 2020-07-06 오후 1:03:57
 * Author : 301-PC-21
 */ 

#include <avr/io.h>

char LED1[] = {0x01, 0x02, 0x04, 0x08};
char LED3[] = {0x11, 0x22, 0x44, 0x88};
char LED2[] = {0x10, 0x20, 0x40, 0x80, 0x00};
int indexj = 0;
int main(void)
{
    /* Replace with your application code */
	DDRC = 0xFF;
	register int i = 0;
	
    while (1) 
    {
		PORTC = LED1[i];
		LED1[i] = LED3[i];
		i++;
		/* 이러한 과정이 없으면 다음 주솟값에 있는 것을 가져온다.
		if(i > 3)
		i = 0;
		*/	
		TestFunction();
		
    }
}

void TestFunction(){
	PORTC |= LED2[indexj];
	indexj++;
	if(indexj > 4)
		indexj = 0;
}
