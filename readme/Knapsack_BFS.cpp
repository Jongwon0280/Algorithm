#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max;
int max_num;
int n = 4;
int mW = 16;
int P[10] = { 0,40,30,50,10 };
int W[10] = { 0,2,5,10,5 };
bool Mc[10];
bool C[10];
typedef struct NODE {
	int level;
	int profit;
	int weight;
}node;
typedef struct QUEUE {
	int front;
	int rear;
	node arr[100];
}Queue;
Queue * init_Q() {
	Queue * preturn = NULL;
	preturn = (Queue *)malloc(sizeof(Queue));
	memset(preturn, 0, sizeof(Queue));
	return preturn;

}
void enqueue(Queue * q,node v) {
	q->rear = (q->rear + 1) % 20;
	q->arr[q->rear] = v;
}
node dequeue(Queue * q) {
	q->front = (q->front + 1) % 20;
	return q->arr[q->front];

}
int bound(node u) {
	int j, k;
	int tot = u.weight;
	int bound = u.profit;
	j = u.level + 1;
	if (u.weight >= mW) {
		return 0;
	}
	while (j <= n && tot + W[j] <= mW) {
		tot += W[j];
		bound += P[j];
		j++;
	}
	k = j;
	if (k <= n) {
		bound += (mW - tot)*(P[k] / W[k]);
	}
	return bound;

}
int knapsack(int n, int mW, int max_num) {
	Queue * q;
	q=init_Q();
	node u, v;
	v.level = 0;
	v.profit = 0;
	v.weight = 0;
	max_num = 0;
	enqueue(q, v);
	while (!(q->front == q->rear)) {
		v=dequeue(q);
		u.level = v.level + 1;
		u.profit = v.profit + P[u.level]; // 다음물건을 챙긴다.
		u.weight = v.weight + W[u.level];
		if (u.weight <= mW&&u.profit > max_num) {
			max_num = u.profit;  
		}
		if (bound(u) > max_num) {
			enqueue(q, u);
		}
		u.profit = v.profit;
		u.weight = v.weight;
		if (bound(u) > max_num) {
			enqueue(q, u);
		}

	}
	return max_num;
}


int main()
{
	
	printf("%d\n", knapsack(n, mW, max_num));
	return 0;
}