#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int map[100][100];
int degree[MAX];
typedef struct STAck {
	int cur;
	int arr[MAX];
}Stack;
void push(Stack * s, int data) {
	if (s->cur < MAX) {
		s->arr[s->cur] = data;
		s->cur++;
	}
}
int pop(Stack * s) {
	if (s->cur!=0) {
		return s->arr[--s->cur];
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
	Stack * s = NULL;
	int tmp;
	s = (Stack *)malloc(sizeof(Stack));
	memset(s, 0, sizeof(Stack));
	degree_init(n);
	for (int i = 0; i < n; i++) {
		if (degree[i] == 0)
			push(s, i);
	}
	while (s->cur != 0) {
		tmp = pop(s);
		printf("%d \n", tmp);
		for (int i = 0; i < n; i++) {
			if (map[tmp][i] == 1) {
				degree[i]--;
				if (degree[i] == 0) {
					push(s, i);
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
			scanf_s("%d",&map[i][j]);
		}

	}
	t_sort(n);
	return 0;
}