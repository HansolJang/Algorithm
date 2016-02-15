#include <stdio.h>
#include <memory.h>

#define SIZE 55

int row, col;
char map[SIZE][SIZE];
int visited[SIZE][SIZE];
int i, j;
int maxStep = 0;

int dirR[4] = {0, 0, 1, -1};
int dirC[4] = {1, -1, 0, 0};

//return step
int dfs(int row, int col);
int max(int a, int b) {
	if(a > b)
		return a;
	else
		return b;
}

int main() {
	char c;
	memset(map, -1, sizeof(map));
	scanf("%d %d", &row, &col);
	for(i = 0; i < row; i++) {
		scanf("%s", &map[i]);
	}

	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++) {
			if(map[i][j] == 'L') {
				memset(visited, 0, sizeof(visited));
				maxStep = max(dfs(i, j), maxStep);
			}
		}
	}

	printf("%d\n", maxStep);
	return 0;
}

int dfs(int row, int col) {
	visited[row][col] = 1;

	int ret = 0;
	int nextR, nextC;
	for(int i = 0; i < 4; i++) {
		nextR = row + dirR[i];
		nextC = col + dirC[i];

		if(nextR >= 0 && nextC >= 0 && nextR < SIZE && nextC < SIZE) {
			if(visited[nextR][nextC] == 0 && map[nextR][nextC] == 'L') {
				ret = max(ret, 1 + dfs(nextR, nextC));
			}
		}
	}

	visited[row][col] = 0;
	return ret;
}