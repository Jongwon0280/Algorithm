#include<stdio.h>
void hanoi(int n,int from, int tmp, int to)
{
	if (n == 1)
		printf("%d���� %d�� �̵�\n", from, to);
	else
	{
		hanoi(n - 1, from, to, tmp); // �ڽź��� ���� �ִ� ��������� ��ȸ������� �̵�
		printf("%d���� %d�� �̵�\n", from, to); // �ڽ��� ��ǥ ������� �̵�
		hanoi(n - 1, tmp, from, to);// ��ȸ��տ� �׾Ƴ��� �ڽ����� �ִ� ���� ����� ��ǥ������� �̵�
	}
}
int main()
{
	hanoi(10, 1, 2, 3);

	return 0;
}