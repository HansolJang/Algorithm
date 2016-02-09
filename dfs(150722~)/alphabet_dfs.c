/*
https://www.acmicpc.net/problem/1987
*/
#include <stdio.h>
#include <memory.h>

#define SIZE 22
#define ALPHABET 26

char board[SIZE][SIZE];
int visited[SIZE][SIZE];
int alphaVisited[ALPHABET];
int R, C;
int dirR[4] = {0, 0, 1, -1};
int dirC[4] = {1, -1, 0, 0};
int i, j;

int dfs(int row, int col);
int max(int a, int b) {
	if(a > b)
		return a;
	else
		return b;
}

int main() {
	memset(visited, 0, sizeof(visited));
	memset(alphaVisited, 0, sizeof(alphaVisited));

	scanf("%d %d", &R, &C);
	for(i = 0; i < R; i++) {
		scanf("%s", &board[i]);
	}
	printf("%d\n", dfs(0, 0));
	return 0;
}

int dfs(int row, int col) {
	int ret = 1;
	int nextR, nextC;
	visited[row][col] = 1;
	alphaVisited[board[row][col] - 'A'] = 1;

	for(int i = 0; i < 4; i++) {
		nextR = row + dirR[i];
		nextC = col + dirC[i];
		if(nextR >= 0 && nextR < R 
			&& nextC >= 0 && nextC < C) {
			if(visited[nextR][nextC] == 0 
				&& alphaVisited[board[nextR][nextC] - 'A'] == 0) {
				ret = max(ret, 1 + dfs(nextR, nextC));
			}
		}
	}
	visited[row][col] = 0;
	alphaVisited[board[row][col] - 'A'] = 0;
	return ret;
}