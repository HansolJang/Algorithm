#include <stdio.h>
#include <memory.h>

int map[55][55];
int cnt; //섬의 갯수
int row, col;

int q[11111][2];
int front, rear;

int dirR[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dirC[8] = {1, -1, 0, 0, 1, -1, 1, -1};

void bfs(int row, int col, int cnt);

int main() {
	while(1) {
		memset(map, 0, sizeof(map));
		scanf("%d %d", &col, &row);

		if(row == 0 && col == 0) {
			break;
		}

		for(int i=1; i<=row; i++) {
			for(int j=1; j<=col; j++) {
				scanf("%d", &map[i][j]);
				if(map[i][j] == 1) {
					map[i][j] = -1;
				}
			}
		}

		front = 1;
		rear = 1;
		cnt = 0;

		for(int i=1; i<=row; i++) {
			for(int j=1; j<=col; j++) {
				if(map[i][j] == -1) {
					bfs(i, j, ++cnt);
				}
			}
		}

		printf("%d\n", cnt);
	}
	
	return 0;
}

void bfs(int row, int col, int cnt) {
	map[row][col] = cnt; //방문
	q[rear][0] = row;    //큐에 삽입
	q[rear++][1] = col;

	//큐가 빌때까지
	while(!(front == rear)) {
		int frow = q[front][0];
		int fcol = q[front][1];
		front++; //pop

		for(int i=0; i<8; i++) {
			int nextR = frow + dirR[i];
			int nextC = fcol + dirC[i];

			// 방문하지 않았고 이어져있음
			if(map[nextR][nextC] == -1) {
				map[nextR][nextC] = cnt;  //방문
				q[rear][0] = nextR;  //push
				q[rear++][1] = nextC;
			}
		}

	}
}