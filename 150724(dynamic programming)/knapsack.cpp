/*
http://59.23.113.171/30stair/01knapsack/01knapsack.php?pname=01knapsack
*/
#include <stdio.h>
#include <memory.h>

#define INF 987654321
#define MAX(a,b) (a) > (b) ? (a) : (b)

typedef struct jewerly
{
	int weight;
	int val;	
};

jewerly arr[111];
int cache[111][11111];
int max_weight;  // 최대로 담을 수 있는 무게
int jcnt;

int solve(int i, int leftWeight);

int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &max_weight);
	scanf("%d", &jcnt);

	int a, b;
	for(int i=0; i<jcnt; i++) {
		jewerly j;
		scanf("%d %d", &j.weight, &j.val);
		arr[i] = j;
	}

	printf("%d\n", solve(0, max_weight));
	
	return 0;
}


//i번째의 보석을 가져갈지 말지 선택할 때,
//앞으로 남은 무게가 leftweight 일때
//얻을 수 있는 최대가치 반환
int solve(int i, int leftWeight) {
	// printf("%d %d\n", i, leftWeight);

	//남은 무게가 없으면 종료
	if(leftWeight < 0) {
		return -(INF);
	}
	//인덱스가 범위 넘어가면 종료
	if(i == jcnt) {
		return 0;
	}

	int& ret = cache[i][leftWeight];
	if(ret != -1) {
		return ret;
	}
	ret = 0;
	//i번째 보석을 선택
	ret = (MAX(ret, arr[i].val + solve(i + 1, leftWeight - arr[i].weight)));
	//i번째 보석을 선택안함
	ret = (MAX(ret, solve(i + 1, leftWeight)));
	return ret;
}