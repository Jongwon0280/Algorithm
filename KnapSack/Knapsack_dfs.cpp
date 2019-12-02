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
	// 유망여부 검사 =>현노드에서 배낭의무게를 초과하지 않는경로 중
	//가치의 상한값(다챙겼을때)이 현재조사된 경로들의 최대 가치(max)보다 작으면, 유망성이 없는 경로임을 판별
	int j = i + 1;  // mW를 초과하게하는 인덱스값
	int tw = w; // mW을 초과하지 않는 물건까지 챙겼을때의 총무게(지금까지 계산된 무게가 초깃값)
	int sum = p; // 경로의 상한값을 계산하기 위함(지금까지 계산된 가치가 초깃값)
	if (w >= mW) { // 무게를 초과하면 유망성이 아예없음
		return false;
	}
	while (j <= n&&tw + W[j] <= mW) { //mW를 초과하지 않는선에서 가치값을 더하고, 무게값을 더한다.
		sum += P[j];
		tw += W[j];
		j++;
	}
	if (j <= n) { //j값이 n을 초과한다는것은 더이상 계산할게 없으므로, 배낭의 잉여무게애대해서 생각해줄 필요없다.
		sum += (mW - tw)*(P[j] / W[j]); // 잉여무게(mW-tw)에 대한 j의 단위별 가치를 곱해준다.
	}
	return sum > max; // 가치의 상한값을 계산해본결과 지금까지 계산된 max_profit보다 작으면, 유망이없다.
}
void knapsack(int i, int weight, int profit) {
	if (max <= profit && weight < mW) { // max_profit보다 profit이 크면 초기화해줌 ,
		max_num = i;
		max = profit;
		for (int i = 1; i <= max_num; i++) { // 기록해둠
			Mc[i] = C[i];
		}
	}
	if (valueAble(i, weight, profit)) { // 경로가 유망하면
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