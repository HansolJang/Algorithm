//https://www.acmicpc.net/problem/11727
#include <cstdio>
#include <cstring>
using namespace std;

int cache[1001];
int n;

int solve(int idx) {
	if (idx == n) return 1;
	if (idx > n) return 0;

	if(cache[idx] != -1) 
		return cache[idx];

	cache[idx] = 0;
	cache[idx] += (solve(idx + 1) + 2 * solve(idx + 2)) % 10007;
	return cache[idx];
}

int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	printf("%d\n", solve(0));
	return 0;
}