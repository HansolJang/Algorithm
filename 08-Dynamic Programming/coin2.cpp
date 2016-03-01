/*
https://www.acmicpc.net/problem/2294
*/
#include <stdio.h>
#include <memory.h>

#define MIN(a,b) (a) > (b) ? (b) : (a)
#define INF 987654321

int cache[111][11111];
int coin[111];
int n,k;

int solve(int i, int leftValue);

int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++) {
		scanf("%d", &coin[i]);
	}

	printf("%d\n", solve(0, k));

	return 0;
}

//i번째 동전을 고려해야 하는 상황일때
//사용할지 말지 선택
//최소의 동전수 반환
int solve(int i, int leftValue) {

	if(leftValue == 0) {
		return 0;
	}

	if(i == n) {
		return INF;
	}

	int& ret = cache[i][leftValue];

	if(ret != -1) {
		return ret;
	}
	ret = INF;
	
	//i번 동전을 s번 사용
	for(int s=0; ;s++){
		if(leftValue - s * coin[i] >= 0)
			//s번 사용했음을 더해줌
			ret = (MIN(ret, s + solve(i + 1, leftValue - s * coin[i])));
		else 
			break;
	}

	return ret;
}