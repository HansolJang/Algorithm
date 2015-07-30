#include <stdio.h>
#include <memory.h>

int M, N, K; //가로, 세로, 배추개수
int ground[55][55];
int q[11111][2];
int front, rear;
int cnt;

int dirR[4] = {0, 0, 1, -1};
int dirC[4] = {1, -1, 0, 0};

void bfs(int row, int col, int cnt);

int main() {
	int itr;
	int nCount;

	scanf("%d", &nCount);

	for(itr=0; itr<nCount; itr++) {
		cnt = 0;
		front = 1;
		rear = 1;
		memset(ground, 0, sizeof(ground));
		scanf("%d %d %d", &M, &N, &K);

		int a, b;
		for(int i=0; i<K; i++) {
			scanf("%d %d", &a, &b);
			ground[b][a] = -1;
		}

		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(ground[i][j] == -1) {
					bfs(i, j, ++cnt);
				}
			}
		}

		printf("%d\n", cnt);
	}
}

void bfs(int row, int col, int cnt) {
	ground[row][col] = cnt;
	q[rear][0] = row;
	q[rear++][1] = col;

	while(!(front == rear)) {

		int frow = q[front][0];
		int fcol = q[front][1];
		front++;

		for(int i=0; i<4; i++) {
			int nextR = frow + dirR[i];
			int nextC = fcol + dirC[i];

			if(nextR >= 0 && nextC >= 0) {
				if(ground[nextR][nextC] == -1) {
					ground[nextR][nextC] = cnt;
					q[rear][0] = nextR;
					q[rear++][1] = nextC;
				}
			}
		}
	}
}