#include<stdio.h>
//str은 비교 대상인 문자열, ptr은 비교할 패턴 문자열  
//n은 str의 길이, m은 ptr의 길이  
int fail[1000] = { 0, };
char ptr[1000] = {'a','b','a','b','a'};
char str[1000] = { 'a','b','a','b','a','a', 'b','a','b','b','a' };
int m=5;
int n=10;
void fail1() 
{
   int i, j;
	    fail[0] = -1;
	    for (i = 1; i < n; i++) {
		       j = fail[i - 1] + 1;
		       while (ptr[i] != ptr[j] && j > 0) {
			            j = fail[j - 1] + 1;
			
		}
		        if (ptr[i] == ptr[j]) {
			           fail[i] = j;
			
		}
		      else {
			            fail[i] = -1;
			
		}
		
	}

}
void comp()
{
	int i, j;
	j = -1;
	for (i = 0; i <= n- 1; i++)
	{
		while (j >= 0 && ptr[j + 1] != str[i]) j = fail[j];
		if (ptr[j + 1] == str[i]) j++;
		if (j == m - 1) {
			printf("패턴이 문자열에서 %d부터 %d에서 일치함\n",i-m+1, i);
			j = fail[j];
		}

	}
}



int main()
{
	int i = 0;

	fail1();
	 comp();




	return 0;
}

