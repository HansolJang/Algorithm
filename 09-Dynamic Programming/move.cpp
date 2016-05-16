//https://www.acmicpc.net/problem/11048
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
#define SIZE 1002
#define INF 987654321
int N, M;
int candy[SIZE][SIZE];
int d[SIZE][SIZE] = {-1, };
int solve(int i, int j) {
	if(i == N && j == M)
		return candy[N][M];
	if(i > N || j > M)
		return -INF;
	if(d[i][j] != -1)
		return d[i][j];
	return d[i][j] = candy[i][j] + max(solve(i + 1, j), solve(i, j + 1));
}
int main() {
	ios_base::sync_with_stdio(false);
	memset(d, -1, sizeof(d));
	cin >> N >> M;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++)
			cin >> candy[i][j];
	}
	cout << solve(1, 1) << '\n';
	return 0;
}