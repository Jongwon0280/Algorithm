#include<stdio.h>
#include<stdlib.h>
int sorted[100];
void merge(int list[], int st, int mid, int end) {
	int i = st;
	int j = mid + 1;
	int k = st;
	while (i <= mid && j <= end) {
		if (list[i] <= list[j]) {
			sorted[k++] = list[i++];
		}
		else {
			sorted[k++] = list[j++];
		}

	}
	if (i <= mid) {
		for (int l = i; l <= mid; l++) {
			sorted[k++] = list[l];
		}
	}
	else{
		for (int l = j; l <=  end; l++) {
			sorted[k++] = list[l];
		}
	}
	for (int l = st; l <= end; l++) {
		list[l] = sorted[l];
	}
}
void merge_sort(int list[], int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(list,start,mid);
		merge_sort(list,mid+1,end);
		merge(list,start,mid,end);
		
	}
}
void print(int arr[]) {
	for (int i = 0; i <= 7; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[100] = { 2,3,4,1,12,4,5,75 };
	merge_sort(arr, 0, 7);
	print(arr);
	system("pause");
	return 0;
}