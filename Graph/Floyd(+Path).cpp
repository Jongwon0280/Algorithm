/*#include<stdio.h>
int map[10][10];
int F[10][10];
void path(int q, int r) {
	if (F[q][r] != 0) {
		path(q, F[q][r]);
		printf("%d ", F[q][r]);
		path(F[q][r], r);
	}
}
void print() {
	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 6; j++) {
			printf("%d | ", map[i][j]);
		}
		printf("\n\n");
	}
	printf("\n\n\n\n\n\n\n");
}
int main()
{
	int k, i, j;
	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 6; j++) {
			if (i == j)
				map[i][j] = 0;
			else {
				map[i][j] = 10000;
			}
		}
	}
	for (int i=0; i <=9 ; i++) {
		int t1, t2,g;
		scanf_s("%d %d %d",&t1,&t2,&g);
		map[t1][t2] = g;
	}
	for ( k = 1; k < 6; k++) {
		
		for (i = 1; i < 6; i++) {
			for (j = 1; j < 6; j++) {
				if (map[i][k] + map[k][j] < map[i][j]) {
					F[i][j] = k;
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
	print();
	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 6; j++) {
			printf("%d ", F[i][j]);
		}
		printf("\n");
	}
	path(4,2);
	printf("\n");
	return 0;
}*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
			if (things[i][0] > j) P[i][j/10] = P[i - 1][j/10];
			else P[i][j / 10] = Max(P[i - 1][j / 10], things[i][1] + P[i - 1][(j - things[i][0]) / 10]);
		}
	}
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= max / 10; j++) {
			printf("%d ", P[i][j]);
		}
		printf("\n");
	}
	return 0;
}