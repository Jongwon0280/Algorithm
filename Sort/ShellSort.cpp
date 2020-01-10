#include<stdio.h>
#include<stdlib.h>
void insertion_sort(int list[], int n, int gap, int i) {
	int k, l;
	for ( k = gap + i; k <= n; k += gap) {
		int tmp = list[k];
		for ( l = k - gap; l >= 0; l -= gap) {
			if (list[l] > tmp) {
				list[l + gap] = list[l];
			}
			else {
				break;
			}
		}
		list[l + gap] = tmp;
	}
}
void Shell_sort(int list[], int n) {
	int gap = n/2;
	int i;
	for (; gap >= 1; gap /= 2) {
		if (gap % 2 == 0 && gap != 0) {   
			gap++;
		}
		for (i = 0; i < gap; i++) {
			insertion_sort(list,n-1,gap,i);
		}
	}
}
void print(int arr[]) {
	for (int i = 0; i <= 7; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main() {
	int arr[100] = { 2,3,4,1,12,4,5,75 };
	Shell_sort(arr, 8);
	print(arr);
	system("pause");
	return 0;
}