#include<stdio.h>
char list[5] = { 'A','B','C','D' }; // 0,1,2,3
void swap(char *a, char *b)
{
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;

}
void per(int n, int i)
{
	if (i == n)
	{
		for (int k = 0; k <= n; k++)
		{
			printf("%c", list[k]);
		}
		printf("\n");

	}
	int j;
	for (j = i; j <= n; j++)
	{
		swap(list+i, list+j);
		per(n, i + 1);

		swap(list+i, list+j);

	}

}
int main()
{
	per(2,0);
	return 0;
}