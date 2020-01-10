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
/*
int n = 6;
int w[] = { 0, 2, 10, 13, 17, 22, 42 };
int W = 52;
bool include[7];

bool promising(int i, int weight, int total) {
	return (weight + total >= W) && (weight == W || weight + w[i + 1] <= W);
}
void sum_of_subset(int i, int weight, int total) {
	if (promising(i, weight, total)) {
		if (weight == W) {
			for (int k = 1; k <= i; k++) {
				if (include[k]) {
					printf("item : %d ", k);
				}
			}
			printf("\n");
		}
		else {
			include[i + 1] = 1;
			sum_of_subset(i + 1, weight + w[i + 1], total - w[i + 1]);
			include[i + 1] = 0;
			sum_of_subset(i + 1, weight, total - w[i + 1]);
		}

	}
}
int main(void) {
	int total = 0;
	for (int i = 1; i <= 6; i++)
		total += w[i];
	sum_of_subset(0, 0, total);
	return 0;
}
/*
item 2,item 6,
item 3,item 4,item 5,
Press any key to continue
*/
