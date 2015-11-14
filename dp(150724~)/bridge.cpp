/*
https://www.acmicpc.net/problem/1010
*/
#include <stdio.h>
#include <memory.h>

int N, M;
int cache[33][33];
int solve(int n, int m);

int main() {
	int itr;
	int nCount;

	scanf("%d", &nCount);
	for(itr=0; itr<nCount; itr++) {
		memset(cache, -1, sizeof(cache));

		scanf("%d %d", &N, &M);
		printf("%d\n", solve(N, M));
	}
	return 0;
}

//서쪽사이트개수(N), 동쪽사이트개수(M)가 주어졌을때
//다리를 놓을 수 있는 가능한 경우의 수 리턴
//mCn = m-1Cn + m-1Cn-1
//m개중 n개를 고르는 가지수
int solve(int n, int m) {

	if(n == m) 
		return 1;
	if(n == 0)
		return 1;

	int& ret = cache[n][m];
	if(ret != -1) {
		return ret;
	}
	ret = 0;
	ret = solve(n, m-1) + solve(n-1, m-1);

	return ret;
}