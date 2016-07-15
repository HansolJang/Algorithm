//https://www.acmicpc.net/problem/2225
#include <cstdio>
#include <cstring>
using namespace std;
int inf = 1000000000;
int N, K;
long long cache[201][201];
//이전에 k번 더해왔 현재 합한 수가 sum일 때, 합이 n이 되는 경우의 수 리턴 
long long solve(int k, int sum) {
	if(sum == N && k == K)
		return 1;
	if(sum > N || k > K)
		return 0;
	if(cache[k][sum] != -1)
		return cache[k][sum];
	cache[k][sum] = 0;
	for(int i=0; i<=N; i++)
		cache[k][sum] += solve(k + 1, sum + i) % inf;
	return cache[k][sum] % inf;
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d %d", &N, &K);
	printf("%d\n", solve(0, 0));
	return 0;
}