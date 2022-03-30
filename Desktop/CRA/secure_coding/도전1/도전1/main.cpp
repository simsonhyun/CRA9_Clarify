#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	//입력 버퍼 만들기 (100글자 까지 허용)
	char* buf = (char*)malloc(101);
	if (buf == NULL) {
		printf("ERROR :: buf 메모리 할당 실패, 메모리 부족\n");
		exit(EXIT_FAILURE);
	}
	scanf("%s", buf);
	//대소문자 담을 공간 만들기
	char* bigChar = (char*)malloc(strlen(buf));
	char* smallChar = (char*)malloc(strlen(buf));
	if (bigChar == NULL) {
		printf("ERROR :: bigChar 메모리 할당 실패, 메모리 부족\n");
		exit(EXIT_FAILURE);
	}
	if (smallChar == NULL) {
		printf("ERROR :: smallChar 메모리 할당 실패, 메모리 부족\n");
		exit(EXIT_FAILURE);
	}
	int bt = 0;
	int st = 0;
	for (int i = 0; buf[i]; i++) {
		if (buf[i] <= 'Z') {
			bigChar[bt++] = buf[i];
		}
		else {
			smallChar[st++] = buf[i];
		}
	}
	bigChar[bt] = '\0';
	smallChar[st] = '\0';
	//소문자를 담을 공간 만들기
	//결과를 저장할 배열
	char result[201];
	strncpy(result, bigChar, strlen(bigChar) + 1);
	strncat(result, smallChar, strlen(smallChar) + 1);
	printf("%s\n", result);
	return 0;
}