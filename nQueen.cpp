#include<stdio.h>
#include<Windows.h>
int R[15], L[15], U[15], count, n;
int map[100][100];
void queen(int y, int x, int n, int R[], int L[], int U[]) {
	if (R[y + x] || L[y - x + n] || U[x]) {
		return;
	}
	else {
		R[y + x] = L[y - x + n] = U[x] = 1;
	}
	if (y == n - 1) {
		count++;
		R[y + x] = L[y - x + n] = U[x] = 0;
		return;
	}
	for (int i = 0; i < n; i++) {
		queen(y + 1, i, n, R, L, U);
	}
	R[y + x] = L[y - x + n] = U[x] = 0;

}
int main()
{
	n = 4; //n by n
	for (int i = 0; i < n; i++) { // column
		queen(0, i, n, R, L, U);
	}
	printf("%d\n", count); // 경우의 수 
	system("pause");
	return 0;
}
