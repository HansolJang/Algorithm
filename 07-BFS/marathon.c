#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define SIZE 111
#define QSIZE 11111
#define INF 987654321
#define TRUE 1
#define FALSE 0

typedef int BOOL;

int col, row, K;
int map[SIZE][SIZE];
typedef struct marathoner 
{
	int row;
	int col;
	int water;
	int height;
} marathoner;
marathoner queue[QSIZE];
int front, rear;
int min_height;

void solve();
BOOL check_arrive(marathoner m);

int min(int a, int b)
{
	if(a > b)
		return b;
	return a;
}

int main(void) {

	setbuf(stdout, NULL);

	int T;
	int test_case;
	int i, j;

	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		// init
		memset(map, 0, sizeof(map));
		// init_queue();
		front = 1;
		rear = 1;
		min_height = INF;
		// input
		scanf("%d %d %d", &col, &row, &K);

		for(i = 0; i < row + 1; i++)
		{
			for(j = 0; j < col + 1; j++)
				scanf("%d", &map[i][j]);
		}

		solve();

		printf("Case #%d\n", test_case);
		printf("%d\n", min_height);
	}

	return 0;
}

void solve()
{
	// first enqueue
	marathoner m;
	m.height = 0;
	m.water = 0;
	m.row = 0;
	m.col = 0;
	queue[rear++] = m;
	front %= QSIZE; 

	while(!(front == rear))
	{
		// dequeue
		marathoner mfront = queue[front++];
		front %= QSIZE;

		// move down
		if(map[mfront.row + 1][mfront.col] != 0)
		{
			marathoner mnext;
			mnext.row = mfront.row + 1;
			mnext.col = mfront.col;
			mnext.height = mfront.height + abs(abs(map[mfront.row][mfront.col]) - abs(map[mnext.row][mnext.col]));
			if(map[mnext.row][mnext.col] < 0)
			{
				mnext.water = mfront.water + 1;
			}
			else
				mnext.water = mfront.water;
				// 도착 안했으면 추가
			if(!check_arrive(mnext))
			{
				queue[rear++] = mnext;
				rear %= QSIZE;
			}
		}

		// move right
		if(map[mfront.row][mfront.col + 1] != 0)
		{
			marathoner mnext;
			mnext.row = mfront.row;
			mnext.col = mfront.col + 1;
			mnext.height = mfront.height + abs(abs(map[mfront.row][mfront.col]) - abs(map[mnext.row][mnext.col]));
			if(map[mnext.row][mnext.col] < 0)
				mnext.water = mfront.water + 1;
			else
				mnext.water = mfront.water;
				// 도착 안했으면 추가
			if(!check_arrive(mnext))
			{
				queue[rear++] = mnext;
				rear %= QSIZE;
			}
		}
	}
}

BOOL check_arrive(marathoner m)
{
	// 도착했는지
	if(m.row == row && m.col == col)
	{	
		// 물의양 조건 만족했는지
		if(m.water >= K)
		{
			min_height = min(min_height, m.height);
		}
		return TRUE;
	}
	return FALSE;
}