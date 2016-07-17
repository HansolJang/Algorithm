//https://www.acmicpc.net/problem/2240
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int T, W;
int cache[31][1001];
int plum[1001] = {0, };
//tree 나무에 있고 현재 w번 움직였고 t초에 있을 때의 최대 자두량 리턴
int solve(int w, int t) {
	if(t == T + 1)
		return 0;
	if(cache[w][t] != -1)
		return cache[w][t];
	cache[w][t] = 0;
	//현재 자리에 자두가 떨어질 경우
	if(plum[t] % 2 != w % 2)
		cache[w][t] = max(cache[w][t], 1 + solve(w, t + 1));
	else {
		//움직여서 자두를 먹을 수 있는 경우
		if(w < W)
			cache[w][t] = max(cache[w][t], 1 + solve(w + 1, t + 1));
		//안 움직이고 먹지 않을 경우
		cache[w][t] = max(cache[w][t], solve(w, t + 1));
	}
	return cache[w][t];
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d %d", &T, &W);
	for(int i=1; i<=T; i++)
		scanf("%d", &plum[i]);
	printf("%d\n", solve(0, 1));
	return 0;
}