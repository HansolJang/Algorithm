/*
https://www.acmicpc.net/problem/9207
*/

#include <stdio.h>
#include <memory.h>

#define MIN(a,b) (a) > (b) ? (b) : (a)
#define INF 987654321

typedef struct pin
{
	int row;
	int col;
	int step;
};

int board[11][11];  //게임보드
int cnt;  //현재 남아있는 핀의 개수
int minCnt;
int minStep;
char str[11][11];

int dirR[4] = {0, 0, 1, -1};
int dirC[4] = {1, -1, 0, 0};

void dfs(int cnt, int step, int (*board)[11]);

int main() {
	int nCount;
	int itr;
	scanf("%d", &nCount);

	for(itr=0; itr<nCount; itr++)
	{
		memset(board, -1, sizeof(board));
		cnt = 0;

		scanf("%s", &str[1]);
		scanf("%s", &str[2]);
		scanf("%s", &str[3]);
		scanf("%s", &str[4]);
		scanf("%s", &str[5]);

		for(int i=1; i<=5; i++)
		{
			for(int j=0; j<11; j++)
			{
				if(str[i][j] == 0) 
					break;
				else if(str[i][j] == 'o')
				{
					board[i][j+1] = 1;
					cnt++;
				}
				else if(str[i][j] == '.')
					board[i][j+1] = 0;
			}
		}

		minCnt = cnt;
		minStep = INF;

		dfs(cnt, 0, board);

		printf("%d %d\n", minCnt, minStep);
	}
	return 0;
}


//남아있는 핀의 개수와 움직인 스텝수, 현재 핀의 위치들
//갈수 있는 곳 다 보기
void dfs(int cnt, int step, int (*board)[11])
{
	if(cnt < minCnt){
		minCnt = cnt;
		minStep = INF;	
	}
	if(cnt == minCnt){
		if(minStep > step)
		{
			minStep = step;
		}
	}

	//갈곳 찾기
	for(int i=1; i<=5; i++){
		for(int j=1; j<10; j++){	
			//현재 위치에 핀이 있음
			if(board[i][j] == 1){
				for(int k=0; k<4; k++){
					int r = i + dirR[k];
					int c = j + dirC[k];

					//인접한 위치에 또 핀이 있음
					if(board[r][c] == 1){	
						//한칸더 옆이 비어있음
						int nr = r + dirR[k];
						int nc = c + dirC[k];
						if(board[nr][nc] == 0){
							board[r][c] = 0; //핀 삭제
							cnt--;
							board[i][j] = 0; //현재위치의 핀은 다다음칸으로 이동
							board[nr][nc] = 1;  //다다음칸

							dfs(cnt, step + 1, board);

							board[r][c] = 1; //되돌리기
							cnt++;
							board[i][j] = 1;
							board[nr][nc] = 0;
						}
					}
				}
			}
		}
	}
}