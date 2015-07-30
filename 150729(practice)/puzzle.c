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

#define INF 987654321

int puzzle[5][5];
int step = 0;
int minStep = INF;

int dirR[4] = {0, 0, 1, -1};
int dirC[4] = {1, -1, 0, 0};

int notSortedCnt(int (*puzzle)[5]);
int solve(int step, int (*puzzle)[5], int (*first)[5]);

int main()
{
	memset(puzzle, -1, sizeof(puzzle));

	for(int i=1; i<4; i++)
	{
		for(int j=1; j<4; j++)
		{
			scanf("%d", &puzzle[i][j]);
		}
	}

	printf("%d\n", solve(1, puzzle, puzzle));
	// printf("%d\n", isNotSorted(puzzle));

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
	int minPuzzle[5][5];
	int cpy[5][5];
	int zrow, zcol;  //0의 위치
	int nxtr, nxtc;  //이동할 칸의 위치
	int minA = INF;  //A* 알고리즘의 최소값
	int astar;   // 답에서 틀린 칸의 개수
	int minastar;  //이번 스텝에서의 경우 중 최소의 답에서 틀린 칸의 개수

	// 초기값과 똑같이 돌아왔다면
	// 답을 만들 수 없음 계속 반복됨 -> 불가능
	if(puzzle == first)
	{
		return -1;
	}

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
			if(astar == 0)  //다 맞춰짐
			{
				return step;  //스텝수 리턴
			}
			// printf("a : %d\n", astar);
			//다 맞춰지지 않았을 경우 최소의 a* 값 찾기
			if(minA > astar + step)  
			{
				minA = astar + step;
				minastar = astar;
				memcpy(minPuzzle, puzzle, sizeof(int) * 5 * 5);

			}
			//다시 이동하기 위한 복원
			memcpy(puzzle, cpy, sizeof(int) * 5 * 5);
		}
	}

	// printf("min a : %d\n", minA);
	return solve(step + 1, minPuzzle, first);

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
			//가장 마지막칸
			if(row == 3 && col == 3 && puzzle[row][col] == 0){
				//cnt++안함
			}
			else
			{
				cnt++;
			}
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