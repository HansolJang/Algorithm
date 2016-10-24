#include <cstdio>
#include <cstring>
using namespace std;
int n, m, k, len, ans = 0;
char board[101][101];
int cache[101][101][81];
char check[81];
int rdir[4] = {0, 0, 1, -1};
int cdir[4] = {1, -1, 0, 0};
bool vaild(int row, int col) {
	if(row >= 0 && row < n && col >= 0 && col < m)
		return true;
	return false;
}
int dfs(int row, int col, int idx) {
	if(idx == len)
		return 1;
	if(cache[row][col][idx] > -1)
		return cache[row][col][idx];
	cache[row][col][idx] = 0;
	for(int i=0; i<4; i++) {
		for(int j=1; j<=k; j++) {
			int nrow = row + rdir[i] * j;
			int ncol = col + cdir[i] * j;
			if(vaild(nrow, ncol) && board[nrow][ncol] == check[idx]) {
				cache[row][col][idx] += dfs(nrow, ncol, idx + 1);
			}
		}
	}
	return cache[row][col][idx];
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0; i<n; i++) {
		scanf("%s", board[i]);
	}
	scanf("%s", check);
	len = strlen(check);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(board[i][j] == check[0]) {
				ans += dfs(i, j, 1);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}