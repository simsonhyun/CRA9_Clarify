#include <stdio.h>
#include <stdlib.h>

int find(const char* buf, char ch) {

	for (int i = 0; buf[i]; i++) {
		if (buf[i] == ch) return i;
	}
	return -1;
}

int main()
{
	const char* str = "SHOW ME THE MONEY";
	char tar = 'Z';

	if (find(str, tar) >= 0) {
		printf("FIND!!\n");
	}
	else {
		printf("¾ø´Ù!!\n");
	}

	return 0;
}