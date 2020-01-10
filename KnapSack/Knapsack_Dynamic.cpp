#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
int things[4][2] = { { 0,0 },{ 5,50 },{ 10,60 },{ 20,140 } };
int P[10][10];
int Max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}
int main()
{
	int n = 3;
	int max = 30;
	for (int i = 1; i <= 3; i++) { // ¹°°Ç
		for (int j = 0; j <= max; j += 10) {
			if (things[i][0] > j) P[i][j] = P[i - 1][j];
			else P[i][j / 10] = Max(P[i - 1][j / 10], things[i][1] + P[i - 1][(j - things[i][0]) / 10]);
		}
	}
	for (int i = 1; i <= 3; i++) {
		for (int j = 0; j <= max / 10; j++) {
			printf("%d ", P[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
	
}