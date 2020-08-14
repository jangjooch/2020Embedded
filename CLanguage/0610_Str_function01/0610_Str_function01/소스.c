#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

int main() {

	char str01[] = "[NAME]JamesHarris[ID]1234[PW]5678\0";
	char *p;
	char rxBuf[] = "[NAME]JamesHarris[ID]1234[PW]5678\n";
	if ((p = strstr(str01, "NAME")) != 0) {
		char temp_str[100];
		char *p1;
		strcpy(temp_str, p);
		p1 = strchr(temp_str, '[');

		p1 = 0;
		printf("strcpy temp_str : %s\n", temp_str);
		printf("idx 5 tempstr : %s\n", &temp_str[5]);
		//printf(&temp_str[5]);
		printf("\n");
		printf("*p : %s", p);
		// = printf(p);
		printf("\n");


		*temp_str = *temp_str + 5;
		printf("%s\n", temp_str);		
		printf("\n");
		printf("%s\n", p);
		printf("\n-----------\n");

		char *parseName;
		parseName = strstr(rxBuf, "[NAME]");
		char *parseID;
		parseID = strstr(rxBuf, "[ID]");
		char *parsePW;
		parsePW = strstr(rxBuf, "[PW]");  
		char temp[100];		

		printf("%d\n", parseID - parseName);

		int nameRange = parseID - parseName;
		strncpy(temp, parseName, nameRange);
		temp[nameRange] = '\0';
		printf("%s\n", &temp[6]);
		
		int idRange = parsePW - parseID;
		strncpy(temp, parseID, idRange);
		temp[idRange] = '\0';
		printf("%s\n", &temp[4]);

		
		char *parseEnd;
		parseEnd = strstr(rxBuf, "\n");
		int pwRange = parseEnd - parsePW;
		//printf("%d\n", parsePW);
		//int pwRange = parsePW;
		strncpy(temp, parsePW, pwRange);
		//temp[8] = '\0';
		printf("%s\n", &temp[4]);
		
	}

	system("pause");
	return 0;
}