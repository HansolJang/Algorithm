#include <stdio.h>
#include <memory.h>
/*
	큐의 사이즈: 존재하는 모든 블럭이 큐에 들어올 수 있는 사이즈 
	https://www.acmicpc.net/problem/7569
*/
#define SIZE 111
#define QSIZE 1111111  //100*100*100

typedef struct tomato
{
	int h;
	int row;
	int col;
	int day;  //며칠 째에 익었는지
};

tomato queue[QSIZE];
int box[SIZE][SIZE][SIZE];  //height, row, col
int M, N, H; //col, row, height
int front, rear;
int not_mature_cnt = 0; // 처음에 입력받은 익지않은 토마토 개수
int mature_cnt = 0;  //총 익힌 토마토 개수
int d_cnt;  //하루에 익힌 토마토 개수
int day;

//동 서 남 북 아래 위
int dirR[6] = {0, 0, 1, -1, 0, 0};
int dirC[6] = {1, -1, 0, 0, 0, 0};
int dirH[6] = {0, 0, 0, 0, 1, -1};

int bfs(int day);  // 그 날 새로 익은 토마토 개수 반환

int main() {
	memset(box, -1, sizeof(box));
	front = 1; rear = 1;
	scanf("%d %d %d", &M, &N, &H);

	for(int h=1; h<=H; h++) {
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=M; j++) {
				scanf("%d", &box[h][i][j]);
				//안익은 토마토개수 세기
				if(box[h][i][j] == 0) not_mature_cnt++;
				//익은채 들어온 것 큐에 삽입
				if(box[h][i][j] == 1) {
					tomato t;
					t.h = h;
					t.row = i;
					t.col = j;
					t.day = 0;
					queue[rear++] = t;
					rear %= QSIZE;
				}
			}
		}
	}

	//안익은 것이 없으면 종료
	if(not_mature_cnt == 0) {
		printf("0\n");
		return 0;
	} 
	// printf("----------not mature cnt: %d\n", not_mature_cnt);
	day = 1;
	while(1) {
		// printf("day %d\n", day);
		d_cnt = bfs(day);
		//그날 새로 익은 토마토가 없으면
		if(d_cnt == 0) {
			break;
		}
		// if(day == 2) break;
		//익은 총 토마토 개수
		mature_cnt += d_cnt;
		day++; //하루 증가
	}

	// printf("\n");
	// for(int h=1; h<=H; h++) {
	// 	for(int i=1; i<=N; i++) {
	// 		for(int j=1; j<=M; j++) {
	// 			printf("%d ", box[h][i][j]);
	// 		}
	// 		printf("\n");
	// 	}
	// 	printf("\n");
	// }

	//모두 익었으면 날짜 출력
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
	/*
		그 전날 익은 것이 팝되면 계속 진행
		1. 방문 (box값 = day+1)
		2. 상하좌우 위 아래 탐색
		3. 갈 수 있는것 큐에 삽입 + 방문
		4. front 팝
	*/
	while(tfront.day == day-1) {
		// printf("day %d maturing.... row: %d col: %d height: %d\n", day, tfront.row, tfront.col, tfront.h);
		front = (front+1) % QSIZE; //pop 성공적으로 꺼내졌을 때만 front증가

		//6방향 탐색
		for(int i=0; i<6; i++) {
			int nextH = tfront.h + dirH[i];
			int nextR = tfront.row + dirR[i];
			int nextC = tfront.col + dirC[i];

			if(box[nextH][nextR][nextC] == 0) {
				tomato nt;
				nt.h = nextH;
				nt.row = nextR;
				nt.col = nextC;
				nt.day = tfront.day + 1; //오늘 날짜로 들어감
				box[nextH][nextR][nextC] = nt.day;  //방문
				queue[rear++] = nt;  //큐에 삽입
				cnt++; //오늘 익은 토마토 개수 증가
				// printf("new mature cnt: %d\n", cnt);
			}
		}

		tfront = queue[front];  //새것 꺼내기
	}
	return cnt;
}