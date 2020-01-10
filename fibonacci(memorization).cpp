#include<stdio.h>
int ck[10000];

int fibo(int n)
{
	if (n == 0 )
		return 0;
	if (n == 1)
		return 1;

	if (ck[n])
	{
		return ck[n];

	}
	else
	{
		ck[n] = fibo(n - 1) + fibo(n - 2);
		return ck[n];


	}

}
int main()
{
	printf("%d\n",fibo(7));

	return 0;
}