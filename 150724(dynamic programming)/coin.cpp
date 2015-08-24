/*
https://www.acmicpc.net/problem/2293
*/
#include <stdio.h>
#include <memory.h>

int cache[111][11111];
int coin[111];
int n, k;
int cpy;

int solve(int i, int leftValue);

int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++) {
		scanf("%d", &coin[i]);
	}
	printf("%d\n", solve(0, k));

	for(int i=0; i<n+1; i++)
	{
		for(int j=0; j<k+1; j++)
		{
			printf("%d ", cache[i][j]);
		}
		printf("\n");
	}

	return 0;
}

//현재 i번째 동전을 사용할 차례일때 
//leftValue만큼 남을 수 있는 경우의 수 리턴
int solve(int i, int leftValue) {
	// printf("%d %d\n", i, leftValue);

	if(leftValue == 0) {
		//성공시 한가지 방법 추가
		return 1;  
	}

	if(i == n) {
		return 0;
	}

	int& ret = cache[i][leftValue];
	if(ret != -1) {
		return ret;
	}
	ret = 0;
	
	//i번 동전을 s번 사용
	for(int s=0; ;s++){
		if(leftValue - s * coin[i] >= 0) {
			//s번 사용했음을 더해줌
			// printf("use %d * %d\n", i, s);
			ret += solve(i + 1, leftValue - s * coin[i]);
		}	
		else
			break;
	}

	return ret;
}