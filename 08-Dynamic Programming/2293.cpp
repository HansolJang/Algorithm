#include <cstdio>
#include <cstring>
using namespace std;

int count, n;
int coin[101];
int cache[101][10001];

int solve(int index, int sum) {
	if(sum == n) return 1;
	else if (sum > n) return 0;
	else if(index >= count) return 0;

	if(cache[index][sum] != -1) return cache[index][sum];
	cache[index][sum] = 0;

	for(int i = 1;; i++) {
		if(i * coin[index] > n) break;
		cache[index][sum] += solve(index + 1, sum + i * coin[index]);
	}
	return cache[index][sum];
}

int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d %d", &count, &n);
	for(int i = 0; i < count; i++) {
		scanf("%d", &coin[i]);
	}
	solve(0, 0);
	int sum = 0;
	for(int i = 0; i < count; i++)
		sum += cache[i][n];
	printf("%d\n", sum);
	return 0;
}