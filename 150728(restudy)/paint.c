/*
https://www.acmicpc.net/problem/1149
*/
#include <stdio.h>
#include <memory.h>

#define MIN(a,b) (a) > (b) ? (b) : (a)
#define INF 987654321

int N;
int price[1111][3];  //0 R, 1 G, 2 B 
int cache[1111][1111];

int solve(int order, int xpaint);

int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		scanf("%d %d %d", &price[i][0], &price[i][1], &price[i][2]);
	}

	printf("%d\n", solve(1, -1));
	
	return 0;
}

//order번째 집을 칠할 순서일때
//직전에 선택한 페인트가 인자로 넘어온다
//order개의 집을 칠하는 최소 가격 리턴
int solve(int order, int xpaint) {

	if(order == N + 1) {
		return 0;
	}

	int& ret = cache[order][xpaint];
	if(ret != -1) {
		return ret;
	}

	ret = INF;

	//첫번째 
	if(xpaint != 0) {
		//R사용
		ret = MIN(ret, price[order][0] + solve(order + 1, 0));
	}

	if(xpaint != 1) {
		//G사용
		ret = MIN(ret, price[order][1] + solve(order + 1, 1));

	}
		
	if(xpaint != 2) {
		//B사용
		ret = MIN(ret, price[order][2] + solve(order + 1, 2));
	}
	
	return ret;

}