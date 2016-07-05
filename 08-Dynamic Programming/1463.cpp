//https://www.acmicpc.net/problem/1463
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int cache[1000001];
int inf = 1000000000;
//n이 1이 되는 연산의 최소 횟수 리턴
int solve(int n) {
	//1에 도달했을 경우
	if(n == 1)
		return 0;
	//1에 도달하지 못했을 경우 제외시키기 위해 무한대값 리턴
	if(n < 1)
		return inf;
	//이미 계산했던 값이면 연산x
	if(cache[n] != -1)
		return cache[n];
	cache[n] = inf;
	//재귀호출할 때 마다 +1 하여 연산횟수 카운트
	cache[n] = min(cache[n], 1 + solve(n - 1));
	if(n % 2 == 0)
		cache[n] = min(cache[n], 1 + solve(n / 2));
	if(n % 3 == 0)
		cache[n] = min(cache[n], 1 + solve(n / 3));
	return cache[n];
}
int main() {
	memset(cache, -1, sizeof(cache));
	int n;
	scanf("%d", &n);
	printf("%d\n", solve(n));
	return 0;
}