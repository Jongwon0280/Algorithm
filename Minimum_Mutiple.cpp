#include<stdio.h>
int M[10][10];
int D[10] = { 20,1,30,10,10 };
int P[10][10];
void order(int i, int j) {
	if (i == j) {
		printf("A%d", i);
		return;
	}
	else {
		int k = P[i][j];
		printf("(");
		order(i, k);
		order(k + 1, j);
		printf(")");
	}
}
int main() {
	int i, j;
	int min = 60000, min_index;
	int n = 4;
	for (int dig = n-1; dig >= 1; dig--) {
		for ( i = 1; i <= dig; i++) {
			j = n - dig + i;
			for (int k = i; k < j; k++) {
				if (min > M[i][k] + M[k + 1][j]+D[i-1]*D[k]*D[j]) {
					min = M[i][k] + M[k + 1][j] + D[i-1] * D[k] * D[j];
					min_index = k;
				}
			}
			M[i][j] = min;
			P[i][j] = min_index;
			min = 60000;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ",P[i][j]);
		}
		printf("\n");
	}
	order(1, 4);
	return 0;
}