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

	return 0;
}

// //남은 가치가 leftValue일때 가능한 방법의 수를 반환
// int solve(int leftValue) {
// 	printf("%d\n", leftValue);

// 	if(leftValue == 0) {
// 		//성공시 한가지 방법 추가
// 		return 1;  
// 	}

// 	if(leftValue < 0) {
// 		return 0;
// 	}

// 	int& ret = cache[leftValue];
// 	if(ret != -1) {
// 		return ret;
// 	}
// 	ret = 0;

// 	for(int i=0; i<n; i++) {
// 		printf("-------------%d\n", i);
// 		ret += solve(leftValue - coin[i]);
// 	}

// 	return ret;
// }

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