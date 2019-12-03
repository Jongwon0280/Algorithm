#include<stdio.h>
int max;
int max_num;
int n = 4;
int mW = 16;
int P[10] = { 0,40,30,50,10 };
int W[10] = { 0,2,5,10,5 };
bool Mc[10];
bool C[10];
bool valueAble(int i, int w, int p) {
	// �������� �˻� =>����忡�� �賶�ǹ��Ը� �ʰ����� �ʴ°�� ��
	//��ġ�� ���Ѱ�(��ì������)�� ��������� ��ε��� �ִ� ��ġ(max)���� ������, �������� ���� ������� �Ǻ�
	int j = i + 1;  // mW�� �ʰ��ϰ��ϴ� �ε�����
	int tw = w; // mW�� �ʰ����� �ʴ� ���Ǳ��� ì�������� �ѹ���(���ݱ��� ���� ���԰� �ʱ갪)
	int sum = p; // ����� ���Ѱ��� ����ϱ� ����(���ݱ��� ���� ��ġ�� �ʱ갪)
	if (w >= mW) { // ���Ը� �ʰ��ϸ� �������� �ƿ�����
		return false;
	}
	while (j <= n&&tw + W[j] <= mW) { //mW�� �ʰ����� �ʴ¼����� ��ġ���� ���ϰ�, ���԰��� ���Ѵ�.
		sum += P[j];
		tw += W[j];
		j++;
	}
	if (j <= n) { //j���� n�� �ʰ��Ѵٴ°��� ���̻� ����Ұ� �����Ƿ�, �賶�� �׿����Ծִ��ؼ� �������� �ʿ����.
		sum += (mW - tw)*(P[j] / W[j]); // �׿�����(mW-tw)�� ���� j�� ������ ��ġ�� �����ش�.
	}
	return sum > max; // ��ġ�� ���Ѱ��� ����غ���� ���ݱ��� ���� max_profit���� ������, �����̾���.
}
void knapsack(int i, int weight, int profit) {
	if (max <= profit && weight < mW) { // max_profit���� profit�� ũ�� �ʱ�ȭ���� ,
		max_num = i;
		max = profit;
		for (int i = 1; i <= max_num; i++) { // ����ص�
			Mc[i] = C[i];
		}
	}
	if (valueAble(i, weight, profit)) { // ��ΰ� �����ϸ�
		C[i + 1] = 1;
		knapsack(i + 1, weight + W[i + 1], profit + P[i + 1]);
		C[i + 1] = 0;
		knapsack(i + 1, weight, profit);
	}
}
int main() {
	knapsack(0, 0, 0);
	printf("Total Item : ");
	for (int k = 1; k <= max_num; k++) {
		if (Mc[k]) {
			printf("item : %d ", k);

		}
	}
	printf("\n");
	printf("Total Profit %d\n", max);
	return 0;
}