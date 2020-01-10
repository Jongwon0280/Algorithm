#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
int parent[MAX];

typedef struct edgetype {
	int start;
	int end;
	int weight;
}Edge;
typedef struct edges {
	int n; // 간선 개수
	edgetype arr[MAX];
}Edges;
void swap(Edges * g, int a, int b) {
	Edge  temp;
	temp = g->arr[a];
	g->arr[a] = g->arr[b];
	g->arr[b] = temp;

}
void init(Edges * edges) {
	memset(edges, 0, sizeof(Edges));
	edges->n = 0;
}
void insert_edge(Edges * edges, int start, int end, int weight) {
	edges->arr[edges->n].start = start;
	edges->arr[edges->n].end = end;
	edges->arr[edges->n].weight = weight;
	edges->n++;
}
int find(int a) {
	int t;
	t = parent[a];
	if (t == -1) {
		return a;
	}
	else {
		while (parent[t] != -1) {
			t = parent[t];
		}
		return t;
	}
}
void Union(int a, int b) {
	if (a > b) {
		parent[a] = b;
	}
	else {
		parent[b] = a;
	}
	
}
void kruskal(Edges * edges) {
	int total = 0,a,b,i=0;
	Edge * e = NULL;
	e = (Edge*)malloc(sizeof(Edge));
	for (int i = 0; i < edges->n; i++) {
		parent[i] = -1;
	}
	while (total <=6 ) {//edges->n - 1
		if (i == edges->n)
			break;
			a = find(edges->arr[i].start);
			b = find(edges->arr[i].end);
			
			if(a!=b){
				printf("%d %d %d 선택! \n", edges->arr[i].start, edges->arr[i].end, edges->arr[i].weight);
				Union(a, b);
				total++;
			}
			i++;
	}
}
void q_sort(Edges * g,int left, int right) {
	if (left < right) {
		int low = left + 1;
		int high = right;
		while (low < high) {
			while (low <= high) {
				if (g->arr[low].weight > g->arr[left].weight) {
					break;
				}
				else {
					low++;
				}
			}
			while (low <= high) {
				if (g->arr[high].weight < g->arr[left].weight) {
					break;
				}
				else {
					high--;
				}
			}
			if (low < high) {
				swap(g, low, high);
			}
		}
		swap(g, high, left);
		q_sort(g, left, high - 1);
		q_sort(g, high + 1, right);
	}
}
void print(Edges * g) {
	for (int i = 0; i <= g->n - 1; i++) {
		printf("%d %d %d\n", g->arr[i].start, g->arr[i].end, g->arr[i].weight);
	}
}
int main()
{
	Edges * g = NULL;
	g = (Edges *)malloc(sizeof(Edges));
	init(g);

	insert_edge(g, 5, 0, 10); ///원래는 가중치별 오름차순 정렬!
	insert_edge(g, 2, 3, 12);
	insert_edge(g, 6, 1, 15);
	insert_edge(g, 4, 5, 27);
	insert_edge(g, 6, 3, 18);
	insert_edge(g, 6, 4, 25);
	insert_edge(g, 3, 4, 22);
	insert_edge(g, 0, 1, 29);
	insert_edge(g, 1, 2, 16);
	q_sort(g, 0, (g->n) - 1);
	print(g);
	kruskal(g);
	for (int i = 0; i <= 9; i++) {
		printf("%d ", parent[i]);
	}
	printf("\n");
	return 0;
}