#include<stdio.h>
int xn(int x, int n)
{
	if (n == 0)
	{
		return 1;

	}
	if (n % 2 == 0)
	{
		return xn(x*x, n / 2);

	}
	else
	{
		return x*xn(x*x, (n - 1) / 2);

	}

}
int main()
{
	printf("%d\n", xn(2, 3));

	return 0;
}