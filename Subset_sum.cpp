#include<stdio.h>
int n, max;
int W[10] = { 0, 2, 10, 13, 17, 22, 8 };
int P[10];
void subset(int lev,int * W,int sum) {
		sum += W[lev] *P[lev] ;
		if (sum > max || lev>n)return;
		if (sum == max ) {
			for (int i = 1; i <= n; i++) {
				if (P[i]) {
					printf("item : %d ", i);
				}
			}
			printf("\n");
			return;
		}	
	P[lev + 1] = 1;
	subset(lev + 1, W, sum);
	P[lev + 1] = 0;
	subset(lev + 1, W, sum);
}
int main()
{
	n = 6;
	max = 30;
	subset(0, W,0);
	return 0;
}

