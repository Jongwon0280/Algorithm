#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int map[100][100];
int degree[MAX];
typedef struct CQueue {
	int cur;
	int front, rear;
	int arr[MAX];
}CQ;
CQ * create(void) {
	CQ * preturn = NULL;
	preturn = (CQ *)malloc(sizeof(CQ));
	memset(preturn, 0, sizeof(CQ));
	return preturn;
}
bool is_full(CQ * cq) {
	return cq->cur == MAX;
}
bool is_empty(CQ * cq) {
	return cq->cur == 0;
}
void enqueue(CQ * cq, int data) {
	if (!is_full(cq)) {
		cq->rear = (cq->rear + 1) % MAX;
		cq->arr[cq->rear] = data;
		cq->cur++;
	}
}
int dequeue(CQ * cq) {
	if (!is_empty(cq)) {
		cq->front = (cq->front + 1) % MAX;
		cq->cur--;
		return cq->arr[cq->front];
		
	}
}
void degree_init(int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (map[j][i] == 1) {
				degree[i]++;
			}
		}
	}
}
void t_sort(int n) {
	CQ * q = create();
	int tmp;
	degree_init(n);
	for (int i = 0; i < n; i++) {
		if (degree[i] == 0)
			enqueue(q, i);
	}
	while (!is_empty(q)) {
		tmp = dequeue(q);
		printf("%d \n", tmp);
		for (int i = 0; i < n; i++) {
			if (map[tmp][i] == 1) {
				degree[i]--;
				if (degree[i] == 0) {
					enqueue(q, i);
				}
			}

		}
	}
}
int main()
{
	int n = 6;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%d", &map[i][j]);
		}

	}
	t_sort(n);
	return 0;
}