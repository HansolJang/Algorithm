//https://www.acmicpc.net/problem/1937
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define SIZE 505
int n;
int map[SIZE][SIZE];
int d[SIZE][SIZE];
int rdir[4] = {0, 0, 1, -1};
int cdir[4] = {1, -1, 0, 0};
int dp(int row, int col) {
	if(d[row][col] != -1)
		return d[row][col];
	d[row][col] = 1;
	int nrow, ncol;
	for(int i=0; i<4; i++) {
		nrow = row + rdir[i];
		ncol = col + cdir[i];
		if(nrow<1 || nrow>n || ncol<1 || ncol>n) continue;
		if(map[row][col] < map[nrow][ncol])
			d[row][col] = max(d[row][col], 1 + dp(nrow, ncol));
	}
	return d[row][col];
}
int main() {
	scanf("%d", &n);
	memset(d, -1, sizeof(d));
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++)
			scanf("%d", &map[i][j]);
	}
	int ans = 0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++)
			ans = max(ans, dp(i, j));
	}
	printf("%d\n", ans);
	return 0;
}