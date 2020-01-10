#include<stdio.h>
#include<Windows.h>
int list[100] = { 5,7,4,9,8,5,6,3 };
void swap(int a, int b) {
	int temp;
	temp = list[a];
	list[a] = list[b];
	list[b] = temp;
}
void q_sort( int left, int right) {
	if (left < right) {
		int low = left + 1;
		int high = right;
		while (low < high) {
			while (low <= high && list[left] > list[low]) {
				low++;
			}
			while (low <= high && list[left] < list[high]) {
				high--;
			}
			if (low < high) {
				swap(low, high);
			}
		}
		swap(left, high);
		q_sort(left, high - 1);
		q_sort(high + 1, right);
	}
}
void print( int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");

}
int main()
{
	
	q_sort( 0, 7);
	print( 8);
	system("pause");
	return 0;
}