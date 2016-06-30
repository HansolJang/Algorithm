//scpc2회 2번문제 징검다리 : dp (시간초과)
#include <cstdio>
#include <memory.h>
using namespace std;
long long int cache[101][50001];
bool bomb[50001];
int n, k, l;
//이전에 x걸음을 걸어 y에 도달할 수 있는 경우의 수 리턴
long long int solve(int x, int y) {
	if(y == n)
		return 1;
	if(y > n)
		return 0;
	if(cache[x][y] != -1)
		return cache[x][y];
	cache[x][y] = 0;
	for(int i=1; i<=k; i++) {
		if(i == x || bomb[y + i])
			continue;
		cache[x][y] += solve(i, y + i) % 1000000009;
	}
	return cache[x][y] %= 1000000009;
}
int main(int argc, char** argv) {
	setbuf(stdout, NULL);
	int T, i, t;
	int test_case;
	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		memset(cache, -1, sizeof(cache));
		memset(bomb, 0, sizeof(bomb));
		scanf("%d %d %d", &n, &k, &l);
		for(i=0; i<l; i++) {
			scanf("%d", &t);
			bomb[t] = true;
		}
		printf("Case #%d\n", test_case);
		printf("%lld\n", solve(0, 0) % 1000000009);
	}
	return 0;
}