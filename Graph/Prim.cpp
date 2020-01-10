#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
#define INF 1000L
typedef struct GraphType {
	int n;
	int weight[MAX][MAX];
}Graph;
int distance[MAX];
int visit[MAX];
void dist_init(int n) {
	for (int i = 0; i < n; i++) {
		distance[i] = INF;
	}
}
int min_in(int n) {
	int min=INF;
	int minindex;
	for (int i = 0; i < n; i++) {
		if (distance[i] < min&& !visit[i])
		{
			min = distance[i];
			minindex = i;
		}

	}
	return minindex;
}
void prim(Graph * g,int s) {
	dist_init(g->n);
	distance[s] = 0;
	int d;
	for (int i = 0; i < g->n; i++) {
		 d =min_in(g->n);
		printf("%d¹æ¹®\n", d);
		visit[d] = 1;
		for (int j = 0; j < g->n; j++) {
			if (distance[j] > g->weight[d][j] && !visit[j]) {
				distance[j] = g->weight[d][j];
			}
		}
	}
}
int main() {
	Graph g = { 7, {{ 0,29,INF,INF ,INF ,10,INF },
	{ 29,0,16,INF ,INF ,INF ,15 },{ INF ,16,0,12,INF ,INF ,INF },
	{ INF ,INF ,12,0,22,INF ,18 },{ INF ,INF ,INF ,22,0,27,25 },
	{ 10,INF ,INF ,INF ,27,0,INF },{ INF ,15,INF ,18,25,INF ,0 } } };
	
	prim(&g, 0);

	return 0;
}