#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
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
	float bound;
}Node;
typedef struct M_heap {
	Node heap[MAX];
	int size;
}Heap;
Heap * mk_heap() {
	Heap * preturn = NULL;
	preturn = (Heap *)malloc(sizeof(Heap));
	memset(preturn, 0, sizeof(Heap));
	return preturn;
}
void insert_heap(Heap * h, Node data) {
	int i = ++h->size;
	while ((i != 1) && data.bound > h->heap[i / 2].bound) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = data;
}
Node delete_heap(Heap * h) {
	int parent = 1, child = 2;
	int i = 1;
	Node item = h->heap[1], tmp = h->heap[h->size--];
	while (child <= h->size) {
		if (child < h->size && h->heap[child].bound < h->heap[child + 1].bound) {
			child++;
		}
		if (tmp.bound > h->heap[child].bound) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = tmp;
	return item;
}
int bound(Node u) {
	int tot = u.weight;
	int bound = u.profit;
	int k;
	int j = u.level + 1;
	if (u.weight > mW) {
		return 0;
	}
	while (j <= n&&tot + W[j] <= mW) {
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
int knapsack(int n) {
	Node u, v;
	Heap * preturn = NULL;
	preturn = mk_heap();
	v.level = 0; v.profit = 0; v.weight = 0;
	v.bound = bound(v);
	insert_heap(preturn,v);
	while (!(preturn->size == 0)) {
		v = delete_heap(preturn);
		if (v.bound > max_num) {
			u.level = v.level + 1;
			u.profit = v.profit + P[u.level];
			u.weight = v.weight + W[u.level];
			u.bound = bound(u);
		}
		if (u.profit > max_num&&u.weight <= mW) {
			max_num = u.profit;
		}
		if (u.bound > max_num) {
			insert_heap(preturn, u);
		}
		u.profit = v.profit;
		u.weight = v.weight;
		if (u.profit > max_num&&u.weight <= mW) {
			max_num = u.profit;
		}
		if (u.bound > max_num) {
			insert_heap(preturn, u);
		}
	}
	return max_num;
}
int main() {
	printf("%d\n",knapsack(n));

	return 0;
}




















/*
int bound(Node u) {
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
int knapsack(int n) {
Node u, v;
Heap * preturn = mk_heap();
v.level = 0; v.profit = 0; v.weight = 0;
max_num = 0;
v.bound = bound(v);
insert_heap(preturn, v);
while (!(preturn->size == 0)) {
v = delete_heap(preturn);
if (v.bound > max_num) {
u.level = v.level + 1;
u.weight = v.weight + W[u.level];
u.profit = v.profit + P[u.level];
if (u.weight <= mW && max_num < u.profit) {
max_num = u.profit;

}
u.bound = bound(u);
if (u.bound > max_num) {
insert_heap(preturn, u);
}
u.weight = v.weight;
u.profit = v.profit;
if (u.bound > max_num) {
insert_heap(preturn,u);
}
}
}
return max_num;
}*/
