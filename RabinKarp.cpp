#include<stdio.h>
int s[100] = {'A','B','A','C','C','E','F','A','B','A','D','D'};
int f[20] = {'C','C','E','F','A'};
int m=5;
int h[100];
int i, j;
int comp1,comp2;
int re;
int pow(int a, int b)
{
	int result = 1;
	int i=1;

	while (i <= b)
	{
		result = result * a;
		i++;

	}
	return result;
}
int main() // A B A C C E F A B A D D     ..  C C E F A
{
	m = 5;

	for (i = 0; i <= m-1; i++)
	{
		re = pow(2, m-i-1);
		comp1 =comp1 +(f[i]*re ); // 고정
		comp2 = comp2 + (s[i] * re); // 문자열 초항
	}
	h[0] = comp2;

	for (i = 1; i <= 11 - m; i++)
	{
		h[i]= (2 * (h[i - 1] - s[i - 1] * pow(2, m - 1)) + s[i + m - 1]);
		if (comp1 == h[i])
		{
			printf("시작위치 : %d 끝위치 : %d\n", i,i+m-1);
			break;
		}
	}

	return 0;
}