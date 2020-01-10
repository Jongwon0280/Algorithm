#include<stdio.h>
int map[10][10];
int seq[10];
int visit[10];
void dfs(int v, int n) {
	visit[v] = 1;
	//printf("정점: %d 순서 :%d\n", v, cnt);
	for (int i = 0; i < n; i++) {
		if (map[v][i] == 1 && !visit[i]) {
			dfs(i, n);
		}
	}
}
void v_init() {
	for (int i = 0; i <= 9; i++) {
		visit[i]=0;
	}
}
int main()
{
	int n=10,k=11; // 정점수 간선수
	
	for (int i = 0; i < k; i++) {
		int t1, t2;
		scanf_s("%d %d", &t1, &t2);
		map[t1][t2] = 1;
		map[t2][t1] = 1;
		
	}
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			if (map[i][j] == 1) {
				map[i][j] = 0;
				dfs(i, n);
				if (visit[j] == 0) {
					printf("브릿지 : %d %d\n", i, j);
					
				}
				map[i][j] = 1;
				v_init();

			}
		}
	}
	
	
	return 0;
}