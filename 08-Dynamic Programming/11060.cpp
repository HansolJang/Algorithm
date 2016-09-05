//https://www.acmicpc.net/problem/11060
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, inf = 1000000000;
int input[1001];
int dp[1001];
int solve(int pos) {
	if(pos == n) 
		return 0; //도착
	if(pos > n)
		return inf; //범위 벗어남
	if(dp[pos] != -1)
		return dp[pos]; //캐싱
	dp[pos] = inf;
	for(int i=1; i<=input[pos]; i++) {
		dp[pos] = min(dp[pos], 1 + solve(pos + i)); //앞으로 간 것 중 최소
	}
	return dp[pos];
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &input[i]);
	int res = solve(1);
	printf("%d\n", res == inf ? -1 : res);
	return 0;
}