#include <stdio.h>
#include <memory.h>

#define SIZE 111
#define QSIZE 11111
#define INF 987654321

typedef struct point
{
	int right;
	int down;
};

typedef struct path
{
	int row;
	int col;
	int fuel; //현재까지의 연료, 각 변의 수를 더한값, G보다 같거나 작아야함
	int step; //현재까지 시간, 최소가 되는 것이 답, 칸 수 *L + 꺽이면 +1
	int turn_cnt;
	bool was_right; //이전에 오른쪽에서 왔으면 true
};

int M, N, L, G;
int front;
int rear;
int ans;
point map[SIZE][SIZE];
path queue[QSIZE];
void solve();

int main()
{
	int nCount;
	int itr;
	scanf("%d", &nCount);
	for(itr = 0; itr<nCount; itr++)
	{
		ans = INF;
		//init map
		point p;
		p.right = 0;
		p.down = 0;
		for(int i=0; i<SIZE; i++)
		{
			for(int j=0; j<SIZE; j++)
			{
				map[i][j] = p;
			}
		}

		scanf("%d %d %d %d", &M, &N, &L, &G);

		//col, right채워넣기
		for(int i=1; i<=M ; i++)
		{
			for(int j=1; j<=N-1; j++)
			{
				scanf("%d", &map[i][j].right);
			}
		}

		//row, down채워넣기
		for(int i=1; i<=M-1; i++)
		{
			for(int j=1; j<=N; j++)
			{
				scanf("%d", &map[i][j].down);
			}
		}

		for(int i=0; i<=M; i++)
		{
			for(int j=0; j<=N; j++)
			{
				printf("[%d][%d] up:%d right:%d\n", i, j, map[i][j].right, map[i][j].down);
			}
			printf("---------------------\n");
		}

		solve();

		if(ans == INF)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
}

void solve()
{
	front = 1;
	rear = 1;
	int c_time;

	//오른쪽으로 한칸 이동
	path start;
	start.row = 1;
	start.col = 2;
	start.fuel = map[1][1].right;
	start.step = 1;
	start.turn_cnt = 0;
	start.was_right = true;
	queue[rear++] = start;
	rear %= QSIZE;

	//밑으로 한칸 이동
	start.row = 2;
	start.col = 1;
	start.fuel = map[1][1].down;
	start.was_right = false;
	queue[rear++] = start;
	rear %= QSIZE;

	while(!(front == rear))
	{
		path pfront = queue[front++];
		front %= QSIZE;

		path pnext;
		pnext.step = pfront.step + 1;

		//오른쪽으로 이동
		if(map[pfront.row][pfront.col].right != 0)
		{
			pnext.row = pfront.row;
			pnext.col = pfront.col + 1;
			pnext.fuel = pfront.fuel + map[pfront.row][pfront.col].right;
			if(!pfront.was_right)
				pnext.turn_cnt = pfront.turn_cnt + 1;
			else
				pnext.turn_cnt = pfront.turn_cnt;

			//연료를 더 적게 사용했음
			if(pnext.fuel <= G)
			{
				//끝, 답과 비교
				if(pnext.row == M && pnext.col == N)
				{
					c_time = pnext.step * L + pnext.turn_cnt;
					printf("step :%d turn_cnt:%d time:%d\n", pnext.step, pnext.turn_cnt, c_time);
					if(ans > c_time)
						ans = c_time;
				}
				//큐에 넣기
				else
				{
					queue[rear++] = pnext;
					rear %= QSIZE;
				}
			}
		}

		//초기화
		pnext.turn_cnt = pfront.turn_cnt;

		//밑으로 이동
		if(map[pfront.row][pfront.col].down != 0)
		{
			pnext.row = pfront.row + 1;
			pnext.col = pfront.col;
			pnext.fuel = pfront.fuel + map[pfront.row][pfront.col].down;
			if(pfront.was_right)
				pnext.turn_cnt = pfront.turn_cnt + 1;
			else
				pnext.turn_cnt = pfront.turn_cnt;

			//연료를 더 적게 사용했음
			if(pnext.fuel <= G)
			{
				//끝, 답과 비교
				if(pnext.row == M && pnext.col == N)
				{
					c_time = pnext.step * L + pnext.turn_cnt;
					printf("step :%d turn_cnt:%d time:%d\n", pnext.step, pnext.turn_cnt, c_time);
					if(ans > c_time)
						ans = c_time;
				}
				//큐에 넣기
				else
				{
					queue[rear++] = pnext;
					rear %= QSIZE;
				}
			}
		}
	}
}
