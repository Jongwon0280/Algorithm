#include<stdio.h>
void hanoi(int n,int from, int tmp, int to)
{
	if (n == 1)
		printf("%d에서 %d로 이동\n", from, to);
	else
	{
		hanoi(n - 1, from, to, tmp); // 자신보다 위에 있는 작은기둥을 우회기둥으로 이동
		printf("%d에서 %d로 이동\n", from, to); // 자신을 목표 기둥으로 이동
		hanoi(n - 1, tmp, from, to);// 우회기둥에 쌓아놓은 자신위에 있던 작은 기둥을 목표기둥으로 이동
	}
}
int main()
{
	hanoi(10, 1, 2, 3);

	return 0;
}