#include<stdio.h>
#define MAX_SIZE 10
int A[10][10];
int R[10][10];
int W[10][10];
int P[5] = { 0, 3,3,1,1 };
int Q[10] = { 2,3,1,1,1 };
void order(int i, int j, int l) {
	if (i == j) {
		printf("위치 : %d, 값 : %d ", l,i);
		return;
	}
	if (i > j)return;
	else {
		int k = R[i][j];
		
		order(i, k - 1,2*l);
		printf("위치 : %d, 값 : %d ",l, k);
		order(k+1, j,2*l+1);

	}
}
int knuth_min(int A[][MAX_SIZE], int R[][MAX_SIZE], int i, int j) {
	int min_val = 5000;
	int min_index;
	for (int k = i+1; k <= j; k++) {
		if (min_val > A[i][k - 1] + A[k][j]) {
			if (min_val == A[i][k - 1] + A[k][j] && min_index > k)// min_val값이 같은경우, 
			{
				min_index = k;
			}
			else if (min_val == A[i][k - 1] + A[k][j] && min_index < k) {
				continue;
			}
			else {
				min_index = k;
				min_val = A[i][k - 1] + A[k][j];
			}
		}

	}
	return min_index;
}
void obst(int P[], int Q[], int A[][MAX_SIZE], int R[][MAX_SIZE], int W[][MAX_SIZE]) {
	int n = 4, k;
	int j;
	for (int i = 0; i < n; i++) {
		W[i][i] = Q[i];
		A[i][i] = 0;
		A[i][i + 1] = W[i][i + 1] = Q[i + 1] + Q[i] + P[i + 1];
		R[i][i] = 0;
		R[i][i + 1] = i + 1;
	}
	W[n][n] = Q[n];
	R[n][n] = 0;
	A[n][n] = 0;
	for (int gap = 2; gap <= n; gap++) {
		for (int i = 0; i <= n - gap; i++) {
			j = i + gap;
			W[i][j] = W[i][j - 1] + P[j] + Q[j];
			k = knuth_min(A, R, i, j);
			A[i][j] = W[i][j] + A[i][k - 1] + A[k][j];
			R[i][j] = k;
		}
	}
	printf("Cost : \n");
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			printf("%d ", A[i][j]);

		}
		printf("\n");
	}
	printf("Weight : \n");
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			printf("%d ", W[i][j]);

		}
		printf("\n");
	}
	printf("Root : \n");
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			printf("%d ", R[i][j]);

		}
		printf("\n");
	}

	order(1, 4,1);
	
}
int main() {

	obst(P, Q, A, R, W);

	return 0;
}

