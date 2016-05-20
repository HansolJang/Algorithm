//https://www.acmicpc.net/problem/1520
#include <iostream>
#include <memory.h>
using namespace std;
#define SIZE 502
int row, col;
int map[SIZE][SIZE];
int d[SIZE][SIZE];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int solve(int i, int j) {
	if(i == row && j == col)
		return 1;
	if(d[i][j] != -1)
		return d[i][j];
	d[i][j] = 0;
	for(int k=0; k < 4; k++) {
		int nr = i + dy[k];
		int nc = j + dx[k];
		if(nr > row || nr <= 0 || nc > col || nc <= 0)
			continue;
		if(map[i][j] > map[nr][nc])
			d[i][j] += solve(nr, nc);
	}
	return d[i][j];
}
int main() {
	ios_base::sync_with_stdio(false);
	memset(d, -1, sizeof(d));
	cin >> row >> col;
	for(int i = 1; i <= row; i++) {
		for(int j = 1; j <= col; j++) 
			cin >> map[i][j];
	}
	cout << solve(1, 1) << '\n';
	return 0;
}