//https://www.acmicpc.net/problem/2688
#include <cstdio>
#include <cstring>
using namespace std;
long long cache[10][65];
int n;
//b자리수 중 1의 자리가 a인 경우의 수 리턴
long long solve(int a, int b) {
	if(b == 1)
		return 1;
	if(cache[a][b] != -1)
		return cache[a][b];
	cache[a][b] = 0;
	for(int i=0; i<10; i++) {
		if(i <= a)
			cache[a][b] += solve(i, b - 1);
	}
	return cache[a][b];
}
int main() {
	int tcase;
	long long ans;
	scanf("%d", &tcase);
	memset(cache, -1, sizeof(cache));
	while(tcase--) {
		scanf("%d", &n);
		ans = 0;
		for(int i=0; i<10; i++)
			ans += solve(i, n);
		printf("%lld\n", ans);
	}
	return 0;
}