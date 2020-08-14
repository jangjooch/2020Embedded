#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main(void){

	char input[] = "[NAME]JANG[ID]1234[PW]qwer[NAME]SH\n";
	int inputLeng = 34;

	char data[100] = { 0, };
	int dataidx = 0;

	char tags[100] = {0, };
	int tagsidx = 0;

	char copy[100] = { 0, };
	int copyidx = 0;

	char state[100] = { 0, };

	int tagstate = 0;
	//int maxstate = 0;
	



	for (int i = 0; i < strlen(input) - 1; i++) {
		if (input[i] != '\n') {
			data[i] = input[i];
		}
		else {
			break;
		}
	}
	strcpy(copy, data);
	printf("data : %s\n", data);
	printf("copy : %s\n", copy);
	char *Stags;
	char *Etags;	
	Stags = strchr(copy, '[');
	Etags = strchr(copy, ']');


	// 태그만 뽑아내기
	while (Stags != NULL) {

		//printf("Ftag : %s\n", Stags);
		//printf("Etag : %s\n", Etags);
		//printf("tagLength : %d\n", tagLeng);
		//printf("Tag : %s\n", &Ftags[tagLeng]);

		int sidx = Stags - copy;
		int eidx = Etags - copy;
		//printf("%d %d\n", sidx, eidx);
		char tagGet[10] = { 0, };
		int tagGetidx = 0;
		for (int i = sidx + 1; i < eidx; i++) {
			tagGet[tagGetidx++] = copy[i];
			//tags[tagsidx++] = copy[i];
		}
		//tags[tagsidx++] = '<';
		//printf("tagGet : %s\n", tagGet);
		char *found;
		found = strstr(tags, tagGet);
		//printf("found : %s\n",found);
		if (found == NULL) {
			//printf("Not Found\n");
			tags[tagsidx++] = tagstate + '0';
			tagstate++;
			for (int i = sidx + 1; i < eidx; i++) {				
				tags[tagsidx++] = copy[i];
			}
			//tags[tagsidx++] = '>';
		}
		
		Stags = strchr(Stags + 1, '[');
		Etags = strchr(Etags + 1, ']');
	}

	printf("tags : %s\n", tags);


	// 뽑은것을 기반으로 작동

	char *tagstart;
	char *tagend;
	char *nexttag;
	tagstart = strchr(copy, '[');
	tagend = strchr(copy, ']');
	nexttag = strchr(tagend + 1, '[');

	while (tagstart != NULL) {
		
		int sidx = tagstart - copy;
		int eidx = tagend - copy;
		
		// 태그 가져오기
		char tagGet[10] = { 0, };
		int tagGetidx = 0;
		for (int i = sidx + 1; i < eidx; i++) {
			tagGet[tagGetidx++] = copy[i];			
		}

		char *found;
		found = strstr(tags, tagGet);

		// 찾은 태그의 바로 앞의 인덱스 추출
		int foundidx = found - tags - 1; 

		if (nexttag != NULL) {
			int scon = tagend - copy;
			int econ = nexttag - copy;
			for (int i = scon + 1; i < econ; i++) {
				state[i] = tags[foundidx];
			}
		}
		else {
			int scon = tagend - copy;
			for (int i = scon + 1; i < strlen(copy); i++) {
				state[i] = tags[foundidx];
			}
		}
		tagstart = strchr(tagstart + 1, '[');
		tagend = strchr(tagend + 1, ']');
		if (tagend != NULL) {
			nexttag = strchr(tagend + 1, '[');
		}
	}
	for (int i = 0; i < 100; i++) {
		printf("%c", state[i]);
	}
	printf("\n");
	for (int i = 0; i < 100; i++) {
		if (state[i] != 0) {
			printf("%c", state[i]);
		}		
	}
	printf("\n");
	printf("tagstate : %d\n", tagstate);


	system("pause");
	return 0;
}