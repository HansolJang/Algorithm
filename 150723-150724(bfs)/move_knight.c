/*
	https://www.acmicpc.net/problem/7562
*/
#include <stdio.h>
#include <memory.h>

#define SIZE 333
#define QSIZE 888888 //300*300*8

typedef struct knight
{	
	int row;
	int col;
	int step;
};

int I;  //체스판크기 4~300
int startR, startC, endR, endC;  //시작과 도착지점
bool visited[SIZE][SIZE];
knight queue[QSIZE];
int front, rear, step;
//나이트의 이동 : 오른쪽위부터 시계방향으로 8칸
int dirR[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dirC[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void bfs(int startR, int startC);

int main() {

	int itr;
	int nCount;

	scanf("%d", &nCount);

	for(itr=0; itr<nCount; itr++) {
		front = 1;
		rear = 1;
		step = 0;
		memset(visited, 0, sizeof(visited));

		scanf("%d", &I); 
		scanf("%d %d", &startR, &startC);
		scanf("%d %d", &endR, &endC);

		// 시작과 도착위치가 같은 경우
		if(startR == endR && startC == endC) {
			printf("0\n");
		} else {
			bfs(startR, startC);
			printf("%d\n", step);
		}
	}

	return 0;
}

void bfs(int startR, int startC) {
	knight k;
	k.row = startR;
	k.col = startC;
	k.step = 0;
	queue[rear++] = k;
	rear %= QSIZE;

	while(!(front == rear)) {
		knight kfront = queue[front++];  //프론트꺼내오기
		visited[kfront.row][kfront.col] = true;  //방문
		front %= QSIZE;  //팝

		for(int i=0; i<8; i++) {
			int nextR = kfront.row + dirR[i];
			int nextC = kfront.col + dirC[i];

			//유효한 인덱스인지 검사
			if(nextR >=0 && nextR < I && nextC >= 0 && nextC < I) {
				if(visited[nextR][nextC] == false) {
					visited[nextR][nextC] = true;  //방문
					knight nextK;
					nextK.row = nextR;
					nextK.col = nextC;
					nextK.step = kfront.step + 1;
					queue[rear++] = nextK;  //삽입
					rear %= QSIZE;
					// printf("enqueue  row:%d col:%d step:%d\n", nextR, nextC, nextK.step);

					if(nextR == endR && nextC == endC) {
						step = nextK.step; //  전역변수에 저장
						return;
					}
				}
			}	
		} //for(8)
	} //while
}