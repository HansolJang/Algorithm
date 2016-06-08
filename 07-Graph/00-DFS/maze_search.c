/*
	https://www.acmicpc.net/problem/2178
*/

#include <stdio.h>
#include <memory.h>

#define NOT_VISITED 99999;

int map[111][111];
int visited[111][111];
int N, M;
void dfs(int row, int col, int step);

//동 서 남 북
int dirR[4] = {0, 0, 1, -1};
int dirC[4] = {1, -1, 0, 0};

int main() {
	for(int i=0; i<111; i++) {
		for(int j=0; j<111; j++) {
			visited[i][j] = NOT_VISITED;
			map[i][j] = -1;
		}
	}

	scanf("%d %d", &N, &M);
	for(int i=1; i<N+1; i++) {
		for(int j=1; j<M+1; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	dfs(1, 1, 1);	

	printf("%d\n", visited[N][M]);

	return 0;
}

/*
	1. 방문
		visited = 거리
	2. 다음에 갈 곳 탐색
		map[][] == 1 이고 visited[][] 가 현재거리보다 크면 선택
	3. 재귀호출
*/

void dfs(int row, int col, int step) {

	visited[row][col] = step;

	// if(row == N && col == M) {
	// 	return;
	// }

	for(int i=0; i<4; i++) {
		int nextR = row + dirR[i];
		int nextC = col + dirC[i];

		// 다음에 쓰여질 스텝값과 비교해야하므로 +1
		if(map[nextR][nextC] == 1 && visited[nextR][nextC] > step + 1) {

			dfs(nextR, nextC, step + 1);
		}
	}
	
}