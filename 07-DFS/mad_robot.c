/*
	https://www.acmicpc.net/problem/1405
	내풀이: 단순할 경우의 모든 확률을 더하기
	다른풀이: 1-(단순할 경우)
		dfs(x, y, step, visited[][]=0, prob) {
			1. 방문
			2. dfs(이동할좌표, , step+1, visited[][]=1, 1*이동할 확률)
		}
*/
#include <stdio.h>

#define SIZE 33

int N; //움직일 횟수, 최대 14번
int map[SIZE][SIZE];
bool visited[SIZE][SIZE];
// 동 서 남 북
int dirR[4] = {0, 0, 1, -1};
int dirC[4] = {1, -1, 0, 0};
double percent[4];
int move; // 현재 움직인 횟수
double per_sum = 0;  // 총 확률
double per = 1; // 단순경로 한개의 확률

void dfs(int row, int col, int move);

int main() {

	for(int i=0; i<SIZE; i++) {
		for(int j=0; j<SIZE; j++) {
			visited[i][j] = false;
		}
	}
	scanf("%d %lf %lf %lf %lf", &N, &percent[0], &percent[1], &percent[2], &percent[3]);
	for(int i=0; i<4; i++) {
		percent[i] = (double)percent[i] / 100;
	}
	
	dfs(SIZE/2, SIZE/2, 0);

	printf("%.10f\n", per_sum);

	return 0;
}

/*
	1. 방문
	2. 4방향으로 이동 (이전에 방문기록이 없다면)
	3. 이동할 방향으로 재귀호출
	4. 방문기록과 확률값 이전으로 복원
*/

void dfs(int row, int col, int move) {
	// printf("%d %d move : %d\n", row, col, move);

	visited[row][col] = true;

	if(move == N) {
		per_sum += per;
		// printf("move == n per_sum : %.10f\n", per_sum);
		return;
	}

	for(int i=0; i<4; i++) {
		int nextR = row + dirR[i];
		int nextC = col + dirC[i];

		// 상하좌우로 무조건 움직인다
		if(visited[nextR][nextC] == false) {
			//복원확률 값
			double cpyper = per;
			//현재 확률
			per *= percent[i];

			// if(i==0) printf("E ");
			// else if(i==1) printf("W ");
			// else if(i==2) printf("S ");
			// else printf("N ");
			// printf("next %d %d  per: %lf\n", nextR, nextC, per);
			
			dfs(nextR, nextC, move + 1);
			/*
				back tracking
				per는 다음으로 이동했을 시의 확률이므로 안갔던 확률로 되돌려줌
				dfs 호출하면 visited[nextR][nextC] = true로 바뀌고 끝나므로
				이전으로 되돌려 주어야한다!
			*/
			per = cpyper;
			visited[nextR][nextC] = false;
		}
	}
} 