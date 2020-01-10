#include<stdio.h>
int R[15],  L[15], U[15],  count, n;
int map[100][100];
void queen(int y, int x,int n,int R[],int L[],int U[]) { // �ٵ��� ������ 10x10
	if (R[y + x] || L[y - x + n] || U[x]) {
		return;
	}
	else {
		printf("(%d %d) ", y, x);
		R[y + x] = L[y - x + n] = U[x] = 1;
	}
	if (y == n - 1) {
		printf("\n\n\n");
		count++;
		R[y + x] = L[y - x + n] = U[x] = 0;
		return;
	}
	for (int i = 0; i < n; i++) {
		queen(y + 1, i,n,R,L,U);
	}
	R[y + x] = L[y - x + n] = U[x] = 0;

}
int main()
{
	n = 10;
	queen(0, 0,n,R,L,U);
	printf("%d\n", count);
	return 0;
}