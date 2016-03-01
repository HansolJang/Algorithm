/*
https://www.acmicpc.net/problem/1525
using A* algorithm
	f(n) = g(n) + h(n) 이 최소가 되는 경우의 수를 따라가기
	g(n) : 현재에서 답과 다른 칸의 개수 (notSortedCnt)
	h(n) : 움직인 횟수 (step)
	=> g(n) == 0 이 되면 h(n)을 리턴
*/
#include <stdio.h>
#include <memory.h>

#define MIN(a,b) (a) > (b) ? (b) : (a)
#define INF 987654321

int puzzle[5][5];
int step = 0;
int minStep = INF;
int a_step[1111];

int dirR[4] = {0, 0, 1, -1};
int dirC[4] = {1, -1, 0, 0};

int notSortedCnt(int (*puzzle)[5]);
int solve(int step, int (*puzzle)[5], int (*first)[5]);

int main()
{
	memset(puzzle, -1, sizeof(puzzle));
	memset(a_step, -1, sizeof(a_step));

	for(int i=1; i<4; i++)
	{
		for(int j=1; j<4; j++)
		{
			scanf("%d", &puzzle[i][j]);
		}
	}

	minStep = solve(1, puzzle, puzzle);
	if(minStep == INF)
		printf("-1\n");
	else
		printf("%d\n", minStep);

	return 0;
}

/*
1 2 3
4 5 6
7 8 0    ->을 만드는 최소 스텝수 반환
step : 몇번 이동했는지 
puzzle : 경우의 수 중에서 a*값이 최소인 퍼즐
first : 가장 초기의 퍼즐, 이것과 같아지면 불가능을 리턴
*/
int solve(int step, int (*puzzle)[5], int (*first)[5])
{
	// printf("--------------%d\n", step);
	int minPuzzle[5][5][5];
	int cpy[5][5];
	int zrow, zcol;  //0의 위치
	int nxtr, nxtc;  //이동할 칸의 위치
	int minA = INF;  //A* 알고리즘의 최소값
	int astar;   // 답에서 틀린 칸의 개수
	int minastar;  //이번 스텝에서의 경우 중 최소의 답에서 틀린 칸의 개수
	int minCnt = 0;

	// 초기값과 똑같이 돌아왔다면
	// 답을 만들 수 없음 계속 반복됨 -> 불가능
	if(step != 1)
	{
		bool is_same = true;
		for(int i=1; i<4; i++)
		{
			for(int j=1; j<4; j++)
			{
				if(puzzle[i][j] != first[i][j])
				{
					is_same = false;
					break;
				}
			}
			if(!is_same)
				break;
		}

		//초기의 게임판으로 돌아왔을 경우 -> 불가능
		if(is_same)
			return INF;
	}

	// 다 맞췄을 경우
	if(notSortedCnt(puzzle) == 0)
	{
		return step - 1;
	}

	if(step > 500)
		return INF;

	memset(minPuzzle, -1, sizeof(minPuzzle));
	memset(cpy, -1, sizeof(cpy));
	//copy
	memcpy(cpy, puzzle, sizeof(int) * 5 * 5);

	//0의 위치 찾기
	for(int i=1; i<4; i++)
	{
		for(int j=1; j<4; j++)
		{
			if(puzzle[i][j] == 0)
			{
				zrow = i;
				zcol = j;
			}
		}
	}
	// printf("zrow : %d  zcol: %d\n", zrow, zcol);

	//a* 최소값인 퍼즐 찾기
	for(int i=0; i<4; i++)
	{
		nxtr = zrow + dirR[i];
		nxtc = zcol + dirC[i];

		if(puzzle[nxtr][nxtc] != -1)
		{
			// printf("next row: %d col: %d\n", nxtr, nxtc);
			puzzle[zrow][zcol] = puzzle[nxtr][nxtc];
			puzzle[nxtr][nxtc] = 0;  //이동

			astar = notSortedCnt(puzzle);  //답과 다른 칸의 개수

			// printf("a : %d\n", astar);
			//다 맞춰지지 않았을 경우 최소의 a* 값 찾기
			if(minA > astar + step)  
			{
				minCnt = 0;
				minA = astar + step;
				minastar = astar;
				memcpy(minPuzzle[minCnt], puzzle, sizeof(int) * 5 * 5);
				minCnt++;
			}
			else if(minA == astar + step)
			{
				memcpy(minPuzzle[minCnt], puzzle, sizeof(int) * 5 * 5);
				minCnt++;
			}
			//다시 이동하기 위한 복원
			memcpy(puzzle, cpy, sizeof(int) * 5 * 5);
		}
	}

	if(a_step[step] == -1)
		a_step[step] = minA;

	int ret = INF;
	if(a_step[step] >= minA)
	{
		for(int i=0; i<minCnt; i++)
		{
			ret = (MIN(ret, solve(step + 1, minPuzzle[i], first)));
		}
	}
	
	return ret;

}

//현재 퍼즐에서 답과 다른 칸의 개수 반환
int notSortedCnt(int (*puzzle)[5])
{
	int row = 1;
	int col = 1;
	int cnt = 0;
	for(int i=1; i<10; i++)
	{
		if(puzzle[row][col] != i)
		{
			//가장 마지막칸이 아니면
			if(!(row == 3 && col == 3 && puzzle[row][col] == 0))
				cnt++;
		} 
		col++;
		if(col % 3 == 1)
		{
			row++;
			col = 1;
		}
	}

	return cnt;
}