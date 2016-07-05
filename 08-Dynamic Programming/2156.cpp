//https://www.acmicpc.net/problem/2156
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int cache[3][10001];
int wine[10001];
int N, inf = 1000000000;
//이전에 n잔 연속마시고 현재 idx번째 잔일 때의 최대 포도주 양 리턴
int solve(int n, int idx) {
	if(idx == N + 1) 
		return 0;
	if(idx < 1)
		return -inf;
	if(cache[n][idx] != -1)
		return cache[n][idx];
	cache[n][idx] = 0;
	//마실 경우
	if(n < 2)
		cache[n][idx] = max(cache[n][idx], wine[idx] + solve(n + 1, idx + 1));
	//마시지 않을 경우
	cache[n][idx] = max(cache[n][idx], solve(0, idx + 1));
	return cache[n][idx];
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		scanf("%d", &wine[i]);
	}
	printf("%d\n", solve(0, 1));
	return 0;
}