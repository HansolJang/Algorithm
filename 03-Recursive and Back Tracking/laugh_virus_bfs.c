/*

VC, GCC에서 사용

*/

#include <stdio.h>
#include <memory.h>

#define SIZE 111
#define QSIZE 111111

typedef struct person
{
	int row;
	int col;
	int step;
};

int map[SIZE][SIZE];
int row, col;
bool visited[SIZE][SIZE];
person queue[QSIZE];
int front, rear;
int brow, bcol;  //폭탄떨어지는 위치
int time;  //모두가 감염되는 시간
int dirR[4] = {0, 0, 1, -1};
int dirC[4] = {1, -1, 0, 0};

void bfs(int row, int col);

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		memset(map, -1, sizeof(map));
		memset(visited, 0, sizeof(visited));
		front = 1;
		rear = 1;
		time = -1;

		printf("#testcase%d\n",itr+1);

		scanf("%d %d", &col, &row);
		for(int r=1; r<=row; r++)
		{
			for(int c=1; c<=col; c++)
			{
				scanf("%d", &map[r][c]);
			}
		}
		scanf("%d %d", &bcol, &brow);

		bfs(brow, bcol);

		printf("%d\n", time);

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}

void bfs(int row, int col)
{
	person p;
	p.row = row;
	p.col = col;
	p.step = 1;
	queue[rear++] = p;
	rear %= QSIZE;
	visited[p.row][p.col] = true;

	while(!(front == rear))
	{
		person pfront = queue[front++];
		front %= QSIZE;

		if(front == rear)
		{
			time = pfront.step;
		}

		for(int i=0; i<4; i++)
		{
			int nextR = pfront.row + dirR[i];
			int nextC = pfront.col + dirC[i];

			if(map[nextR][nextC] == 1 && visited[nextR][nextC] == false)
			{
				person pnext;
				pnext.row = nextR;
				pnext.col = nextC;
				pnext.step = pfront.step + 1;
				visited[pnext.row][pnext.col] = true;
				queue[rear++] = pnext;
				rear %= QSIZE;
			}
		}
	}
}

/*
어느 도서관에서 게릴라들이 웃음 폭탄을 떨어뜨렸습니다. 
이 폭탄 내 바이러스에 노출되면 평생 웃어야 하는 무서운 바이러스입니다. 
이 폭탄은 폭탄 주위에 있는 네 사람(상,하,좌,우)을 1초동안에 바이러스에 감염시키며, 
다시 1초가 지나면 감염된 사람 주위에 있는 네 사람을 다시 바이러스에 감염시킵니다. 
그러나 인접해있는 네 방향이 아니면 웃음 바이러스에 감염되지 않습니다. 
아래 [그림1]은 폭탄이 떨어진 위치와 사람들의 위치를 나타낸 것이고, 
[그림2]는 바이러스가 퍼져나가는 모습을 1초 단위로 나타낸 것으로서 도서관 전체 학생이 감염되는데 8초가 걸립니다.

		O	O			
O	O	O	O		O	
		O		O	O	O
	O	O	O	O		O
		●		O	O	
	O	O	O	O		
		O		O	O	O
				O		
[그림 1]

위의 그림을 보면 7 X 8 크기의 맵에 ( 3 , 5 )지점에 폭탄이 떨어졌습니다.
아래 그림은 폭탄으로 인한 바이러스 확산을 보여줍니다.

		5	6			
6	5	4	5		7	
		3		5	6	7
	3	2	3	4		8
		1		5	6	
	3	2	3	4		
		3		5	6	7
				6		
[그림2]

문제는 빠르게 퍼져나가는 웃음 바이러스 감염을 막기 위해 
도서관이 마지막으로 감염되는 시간이 얼마인지 계산하는 것 입니다.

[입력]
입력에는 여러 테스트 케이스가 포함될 수 있다. 입력의 첫째 줄에는 테스트 케이스의 수 T가 주어지고, 
이후 차례로 T개의 테스트 케이스가 주어진다 (T ≤ 30)
각 테스트 케이스의 첫 줄에 도시의 가로와 세로 N, M이 공백으로 분리되어 주어진다. (1 ≤ N, M ≤ 100)
두 번째 줄부터 N개의 줄에 걸쳐 도서관 안의 상황이 공백으로 분리되어 주어진다. 1은 사람이 있다는 것이고, 
0은 사람이 없다는 것이다. 
마지막 줄에는 생화학 웃음 폭탄이 떨어지는 곳의 가로와 세로 좌표가 공백으로 분리되어 주어진다.

[출력]
각 테스트 케이스의 첫 줄에 감염될 수 있는 사람이 모두 감염될 때까지 몇 초가 걸리는지를 출력한다. 
(중요! 테스트 케이스 개수마다 #testcase번호를 출력 후 정답 출력)

[STL사용 불가]

[입출력 예]

입력
2
7 8
0 0 1 1 0 0 0
1 1 1 1 0 1 0
0 0 1 0 1 1 1
0 1 1 1 1 0 1
0 0 1 0 1 1 0
0 1 1 1 1 0 0
0 0 1 0 1 1 1
0 0 0 0 1 0 0
3 5
10 10
1 1 1 1 0 1 1 0 0 0
0 1 1 1 1 1 0 1 1 0
0 0 1 1 0 1 0 1 1 1
0 1 1 1 1 1 0 0 1 1
0 1 0 1 0 1 1 1 1 0
0 0 0 0 0 1 1 0 0 0
1 0 1 0 1 0 1 1 0 0
0 0 1 1 1 1 1 1 1 1
1 0 1 0 0 1 0 1 1 0
1 1 1 0 0 0 0 1 1 1
2 2

출력 
#testcase1
8
#testcase2
21
*/