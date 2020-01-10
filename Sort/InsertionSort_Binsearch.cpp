#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
typedef struct node {
	int num;
}Node;
typedef struct List {
	int n;
	node * array;
}list;
int bin_search(list * List, int n, int key) {
	int low = 1;
	int high = n;
	int mid;
	int loc = 0;
	while (loc == 0 && low <= high) {
		mid = (low + high) / 2;
		if (List->array[mid].num == key) loc = mid;
		else if (List->array[mid].num > key) high = mid - 1;
		else low = mid + 1;
	}
	if (loc == 0)
		loc = low;
	return loc;
	
}
void asecending_insert_sort(list * List,int n) {
	int j;
	int key;
	for (int i = 2; i <= n; i++) {
		 key = List->array[i].num;
		 int loc =bin_search(List, i-1, key);
		 for(int j=i;j>loc;j--){
			 List->array[j].num = List->array[j - 1].num;
		}
		List->array[loc].num = key;
	}
}
void descending_insert_sort(list * List, int n) {
	int j;
	for (int i = 1; i <= n - 1; i++) {
		j = i - 1;
		int key = List->array[i].num;
		while (j >= 0) {
			if (List->array[j].num < key) {
				List->array[j+1].num = List->array[j].num;
				j--;
			}
			else {
				break;
			}
		}
		List->array[j + 1].num = key;
	}
}
list * create() {
	list * plink = NULL;
	plink = (list *)malloc(sizeof(list));
	memset(plink, 0, sizeof(list));
	plink->array = (Node *)malloc(sizeof(Node) * 10);
	return plink;
}
void print(list * List) {
	for (int i = 1; i <= 6; i++) {
		printf("%d ", List->array[i].num);
	}
	printf("\n");
}
int main()
{
	list * preturn = create();
	preturn->array[1].num = 5;
	preturn->array[2].num = 3;
	preturn->array[3].num = 8;
	preturn->array[4].num = 4;
	preturn->array[5].num = 9;
	preturn->array[6].num= 6;
	asecending_insert_sort(preturn, 6);
	print(preturn);
	//descending_insert_sort(preturn, 6);
	//print(preturn);
	system("pause");
	return 0;
}