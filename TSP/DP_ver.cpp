#include<stdio.h>
#define M 10000000
int W[10][10] = { {0,2,9,M},{1,0,6,4},{M,7,0,8},{6,3,M,0} };
int P[17][65536];
int Pa[10];
int n = 4;
int min(int a, int b) {
	return (a > b) ? b : a;
}
/*int tsp(int cur, int mask) {
	
	if (mask == (1 << n) - 1) {
		P[cur][mask] = W[cur][0];
		return W[cur][0];
	}
	int& res = P[cur][mask];
	if (res != 0) {
		return res;
	}
	res = M;
	for (int next = 0; next < n; next++) {
		if (mask&(1 << next))continue;
		if (W[cur][next] == 0) continue;
		res = min(res, tsp(next, mask + (1 << next)) + W[cur][next]);   
	}
	return res;
}
void path(int dis) {
	int mask = 1;
	int piv = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (mask & (1 << k))continue;
			if (dis - W[piv][k] == P[k][mask + (1 << k)]) {
				Pa[cnt] = k;
				cnt++;
				dis = P[k][mask + (1 << k)];
				piv = k;
				mask += (1 << k);
			}
		}
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d ", Pa[i]);
	}
	printf("\n");
}*/
int tsp(int cur, int mask) {
	if (mask == (1 << n) - 1)
	{
		P[cur][mask] = W[cur][0];
		return W[cur][0];
	}
	int& res = P[cur][mask];
	if (res != 0) {
		return res;
	}
	res = M;
	for (int next = 0; next < n; next++) {
		if (mask&(1 << next))continue;
		if (W[cur][next] == 0) continue;
		res = min(res, tsp(next, (1 << next) + mask) + W[cur][next]);

	}
	return res;
}
void path(int dis) {
	int mask = 1;
	int piv = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (mask & (1 << k)) continue;
			if (dis - W[piv][k] == P[k][(1 << k) + mask]) {
				Pa[cnt] = k;
				cnt++;
				dis = P[k][(1 << k) + mask];
				mask += (1 << k);
				piv = k;

			}
		}
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d ", Pa[i]);
	}
	printf("\n");
}
int main() {
	int d = tsp(0, 1);
	printf("%d\n", d);
	path(d);
	
	return 0;
}








































