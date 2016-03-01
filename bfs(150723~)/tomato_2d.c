#include <stdio.h>
#include <memory.h>
/*
	큐의 사이즈: 존재하는 모든 블럭이 큐에 들어올 수 있는 사이즈 
	https://www.acmicpc.net/problem/7569
*/
#define SIZE 1111
#define QSIZE 1111111  //100*100*100

typedef struct tomato
{
	int row;
	int col;
	int day;  //며칠 째에 익었는지
} tomato;

tomato queue[QSIZE];
int box[SIZE][SIZE];  //height, row, col
int M, N; //col, row, height
int front, rear;
int not_mature_cnt = 0; // 처음에 입력받은 익지않은 토마토 개수
int mature_cnt = 0;  //총 익힌 토마토 개수
int d_cnt;  //하루에 익힌 토마토 개수
int day;

//동 서 남 북
int dirR[4] = {0, 0, 1, -1};
int dirC[4] = {1, -1, 0, 0};

int bfs(int day);  // 그 날 새로 익은 토마토 개수 반환

int main() {
	memset(box, -1, sizeof(box));
	front = 1; rear = 1;
	scanf("%d %d", &M, &N);

	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			scanf("%d", &box[i][j]);
			//안익은 토마토개수 세기
			if(box[i][j] == 0) not_mature_cnt++;
			//익은채 들어온 것 큐에 삽입
			if(box[i][j] == 1) {
				tomato t;
				t.row = i;
				t.col = j;
				t.day = 0;
				queue[rear++] = t;
				rear %= QSIZE;
			}
		}
	}

	if(not_mature_cnt == 0) {
		printf("0\n");
		return 0;
	} 
	day = 1;
	while(1) {
		d_cnt = bfs(day);
		if(d_cnt == 0) {
			break;
		}
		mature_cnt += d_cnt;
		day++;
	}

	if(not_mature_cnt == mature_cnt) {
		printf("%d\n", day-1);
	} else {
		printf("-1\n");
	}
	return 0;
}

int bfs(int day) {
	int cnt = 0;
	tomato tfront = queue[front];	
	while(tfront.day == day-1) {
		front = (front+1) % QSIZE; //pop 성공적으로 꺼내졌을 때만 front증가
		for(int i=0; i<4; i++) {
			int nextR = tfront.row + dirR[i];
			int nextC = tfront.col + dirC[i];

			if(box[nextR][nextC] == 0) {
				tomato nt;
				nt.row = nextR;
				nt.col = nextC;
				nt.day = tfront.day + 1; //오늘 날짜로 들어감
				box[nextR][nextC] = nt.day;  //방문
				queue[rear++] = nt;  //큐에 삽입
				cnt++; //오늘 익은 토마토 개수 증가
			}
		}
		tfront = queue[front];  //새것 꺼내기
	}
	return cnt;
}