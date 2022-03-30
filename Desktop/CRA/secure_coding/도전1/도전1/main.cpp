#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	//�Է� ���� ����� (100���� ���� ���)
	char* buf = (char*)malloc(101);
	if (buf == NULL) {
		printf("ERROR :: buf �޸� �Ҵ� ����, �޸� ����\n");
		exit(EXIT_FAILURE);
	}
	scanf("%s", buf);
	//��ҹ��� ���� ���� �����
	char* bigChar = (char*)malloc(strlen(buf));
	char* smallChar = (char*)malloc(strlen(buf));
	if (bigChar == NULL) {
		printf("ERROR :: bigChar �޸� �Ҵ� ����, �޸� ����\n");
		exit(EXIT_FAILURE);
	}
	if (smallChar == NULL) {
		printf("ERROR :: smallChar �޸� �Ҵ� ����, �޸� ����\n");
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
	//�ҹ��ڸ� ���� ���� �����
	//����� ������ �迭
	char result[201];
	strncpy(result, bigChar, strlen(bigChar) + 1);
	strncat(result, smallChar, strlen(smallChar) + 1);
	printf("%s\n", result);
	return 0;
}