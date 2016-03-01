/*
	http://59.23.113.171/30stair/maze/maze.php?pname=maze
	입구 : (N, 1)
	출구 : (1, M)
	최단 거리 출력, 갈 수 없을 시 -1 출력
*/
#define NOT_VISITED 99999;

#include <stdio.h>
#include <memory.h>

int N, M;
int city[22][22];
int visited[22][22];
int dirR[4] = {0, 0, 1, -1};
int dirC[4] = {1, -1, 0, 0};

void dfs(int row, int col, int step);

int main() {

	memset(city, -1, sizeof(city));

	scanf("%d %d", &N, &M);
	for(int i=1; i<N+1; i++) {
		for(int j=1; j<M+1; j++) {
			scanf("%1d", &city[i][j]);
			visited[i][j] = NOT_VISITED;
		}
	}

	dfs(N, 1, 1);

	//초기화 했던 값 = 99999 
	if(visited[1][M] == 99999) {
		printf("-1\n");
	} else {
		printf("%d\n", visited[1][M]);
	}

	return 0;
}

void dfs(int row, int col, int step) {

	visited[row][col] = step;

	for(int i=0; i<4; i++) {
		int nextR = row + dirR[i];
		int nextC = col + dirC[i];

		if(city[nextR][nextC] == 0 && visited[nextR][nextC] > step + 1) {
			dfs(nextR, nextC, step + 1);
		}
	}
}