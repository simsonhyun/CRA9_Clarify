#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define MAXSIZE 10
#define RANDLIMIT 142573
int(*map)[MAXSIZE];
void msleep(int ms)
{
	//sec ��ŭ ����ϴ� �ڵ�
	int cycle = ms * 100000;
	for (int i = 0; i < cycle; i++);
}
void fillDummyRandData() {
	//0 ~ 150 ������ �̿�, ���������� ����
	for (int y = 0; y < MAXSIZE; y++) {
		for (int x = 0; x < MAXSIZE; x++) {
			int ret = 0;
			while (1) {
				ret = rand() % RANDLIMIT;
				if (ret >= 0 && ret <= 150) continue;
				break;
			}
			map[y][x] = ret;
		}
	}
}
int ioctl(int dev, int val)
{
	//HW Module ���� �ڵ� ���, ������ ���
	//������ 1 ����, ���н� 0
	return ((rand() % 10 == 0) ? 1 : 0);
}
int read(int dy, int dx)
{
	int ret = map[dy][dx];
	return ioctl(0, ret);
}
int isNumber(char* nums) {
	for (int i = 0; nums[i]; i++) {
		if (nums[i] >= '0' && nums[i] <= '9') continue;
		return 0;
	}
	return 1;
}
int isDouble(char* nums) {
	//.�� �ϳ� �Ǵ� 0 �� �־�� ��
	int cnt = 0;
	for (int i = 0; nums[i]; i++) {
		if (nums[i] == '.') cnt++;
		if (cnt >= 2) return 0;
	}
	//. ���ڸ� ���
	for (int i = 0; nums[i]; i++) {
		if (nums[i] >= '0' && nums[i] <= '9') continue;
		if (nums[i] == '.') continue;
		return 0;
	}
	return 1;
}
int isValid(int argc, char* argv[]) {
	if (argc != 4) return 0;
	if (!isNumber(argv[1])) return 0;
	if (!isNumber(argv[2])) return 0;
	if (!isDouble(argv[3])) return 0;
	return 1;
}
int isBoudary(int dy, int dx, float delay) {
	if (!(dy >= 0 && dy <= 9)) return 0;
	if (!(dx >= 0 && dx <= 9)) return 0;
	if (!(delay >= 1 && delay <= 100)) return 0;
	return 1;
}
int main(int argc, char* argv[])
{
	if (!isValid(argc, argv)) {
		printf("ERROR :: �ƱԸ�Ʈ �߸��Ǿ���\n");
		exit(EXIT_FAILURE);
	}
	int mappingTable[MAXSIZE][MAXSIZE];
	map = mappingTable;
	fillDummyRandData();
	int dy = atoi(argv[1]);
	int dx = atoi(argv[2]);
	float ms_delay = atof(argv[3]);
	int start = clock();
	if (!isBoudary(dy, dx, ms_delay)) {
		printf("ERROR :: ��� ���� �ȿ��ִ� ���� �ƴϴ�");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < 1000; i++) {
		int retryCnt = 5;
		int ret = 0;
		while (retryCnt--) {
			ret = read(dy, dx);
			if (ret == -1) continue;
			break;
		}
		if (ret == -1) {
			printf("ERROR :: 5ȸ read fail ��ȸ�� �־�����, ��� ����\n");
			exit(EXIT_FAILURE);
		}
		msleep(ms_delay);
	}
	int latency = clock() - start;
	if (latency > 5000) {
		printf("ERROR REPORT :: LATENCY OVER\n");
		return 0;
	}
	printf("%d ms", latency);
	return 0;
}