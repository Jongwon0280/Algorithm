#include<stdio.h>
int W[10][10] = {
	{0, 0, 0, 0, 0, 0, 0, 0 }
,{0,0, 1, 1, 0, 0, 0, 1, 1 }
,{0,1, 0, 1, 0, 0, 0, 1, 1},
{0,1, 1, 0, 1, 0, 0, 0, 0 }
,{0,0, 0, 1, 0, 1, 0, 0, 0},
{0,0, 0, 0, 1, 0, 1, 0, 0},
{0,0, 0, 0, 0, 1, 0, 1, 0},
{0,1, 1, 0, 0, 0, 1, 0, 1},
{0,1, 1, 0, 0, 0, 0, 1, 0} };
int Path[10]; // 경로기록
int n = 8;
bool valueable(int index) {
	int j;
	bool s;
	if (index == n - 1 && !W[Path[n - 1]][Path[0]]) {
		s = false;
	}
	else if (index > 0 && !W[Path[index - 1]][Path[index]])  //연결여부 확인
	{
		s = false;
	} else {
		s = true;
		j = 1;
		while (j < index && s) {
			if (Path[index] == Path[j]) {
				s = false;
			}
			j++;
		}
	}
	return s;
}
void hamitonian(int i) {
	if (valueable(i)) {
		if (i == n - 1) {
			for (int i = 0; i < n; i++) {
				printf("%d ", Path[i]);
			}
			printf("\n");
		}
		else {
			for (int j = 2; j <= n; j++) {
				Path[i + 1] = j;
				hamitonian(i+1);

			}
		}
	}
	
	
}
int main() {
	
	Path[0] = 1;
	hamitonian(0);

	return 0;
}