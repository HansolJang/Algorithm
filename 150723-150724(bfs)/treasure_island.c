/*
	https://www.acmicpc.net/problem/2589
*/
#include <stdio.h>
#include <memory.h>

#define QSIZE 111111
#define SIZE 55

int row, col;
bool visited[SIZE][SIZE];
int queue[QSIZE][3];
char map[SIZE][SIZE];
int front, rear, step;
int max_step = 0;

int dirR[4] = {0, 0, 1, -1};
int dirC[4] = {1, -1, 0, 0};

int bfs(int row, int col, int step);
void initialize();

int main() {

	scanf("%d %d", &row, &col);
	for(int i=0; i<=row; i++) {
		scanf("%s", &map[i]);
		scanf("\n");
	}
	
	for(int i=0; i<row; i++) {
		for(int j=0; j<col; j++) {
			if(map[i][j] == 'L') {
				// printf("new start row:%d col:%d\n", i, j);
				initialize();
				step = bfs(i, j, 0);
				if(max_step < step) max_step = step;
			}
		}
	}

	printf("%d\n",max_step);
	return 0;
}

void initialize() {
	for(int i=0; i<SIZE; i++) {
		for(int j=0; j<SIZE; j++) {
			visited[i][j] = false;
		}
	}
	front = 1;
	rear = 1;
}

int bfs(int row, int col, int step) {
	visited[row][col] = true;
	queue[rear][0] = row;
	queue[rear][1] = col;
	queue[rear++][2] = step;
	rear %= QSIZE;

	while(!(front == rear)) {	
		int frow = queue[front][0];
		int fcol = queue[front][1];
		int fstep = queue[front++][2];
		front %= QSIZE;

		for(int i=0; i<4; i++) {
			int nextR = frow + dirR[i];
			int nextC = fcol + dirC[i];

			if(nextR >= 0 && nextC >= 0) {
				if(visited[nextR][nextC] == false && map[nextR][nextC] == 'L') {
					// printf("next row:%d col:%d, step:%d\n", nextR, nextC, fstep+1);
					visited[nextR][nextC] = true;
					queue[rear][0] = nextR;
					queue[rear][1] = nextC;
					queue[rear++][2] = fstep + 1;
					rear %= QSIZE;
				}
			}
		}
	}
	return queue[(front-1)%QSIZE][2];
}