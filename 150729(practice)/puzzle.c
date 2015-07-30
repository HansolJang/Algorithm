/*
https://www.acmicpc.net/problem/1525
using A* algorithm
*/
#include <stdio.h>
#include <memory.h>

#define INF 987654321

int puzzle[5][5];
int step = 0;
int minStep = INF;

int dirR[4] = {0, 0, 1, -1};
int dirC[4] = {1, -1, 0, 0};

int isNotSorted(int (*puzzle)[5]);
int solve(int step, int (*puzzle)[5]);

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

	printf("%d\n", solve(1, puzzle));
	// printf("%d\n", isNotSorted(puzzle));

	return 0;
}

/*
1 2 3
4 5 6
7 8 0    ->을 만드는 최소 스텝수 반환
*/
int solve(int step, int (*puzzle)[5])
{
	printf("%d\n", step);
	int minPuzzle[5][5];
	int cpy[5][5];
	int sameCnt = 0;
	int zrow, zcol;  //0의 위치
	int nxtr, nxtc;  //이동할 칸의 위치
	int minA = INF;  //A* 알고리즘의 최소값
	int astar;
	memset(minPuzzle, -1, sizeof(minPuzzle));
	memset(cpy, -1, sizeof(cpy));

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
	printf("zrow : %d  zcol: %d\n", zrow, zcol);

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

			astar = isNotSorted(puzzle);  //답과 다른 칸의 개수
			if(astar == 0)  //다 맞춰짐
			{
				return step;  //스텝수 리턴
			}
			printf("a : %d\n", astar + step);
			//다 맞춰지지 않았을 경우 최소의 a* 값 찾기
			if(minA > astar + step)  
			{
				minA = astar + step;
				// sameCnt = 0;
				memcpy(minPuzzle, puzzle, sizeof(int) * 5 * 5);

			}
			//중복값이 있을 경우 모든 경우의 수 확인해야함
			// else if (minA == astar + step)
			// {	
			// 	printf("---------same astar %d\n", astar);
			// 	memcpy(minPuzzle[++sameCnt], puzzle, sizeof(int) * 5 * 5);
			// }

			//복원
			memcpy(puzzle, cpy, sizeof(int) * 5 * 5);
		}
	}

	// printf("min a : %d\n", minA);

	int ret = 0;
	// printf("sameCnt : %d\n", sameCnt);
	//최소값이 중복일 경우 모든 경우의 수에서 다시 확인
	// for(int i=0; i<=sameCnt; i++)
	// {
	//최소값이 중복될 경우 가장 먼저 찾은 하나에서 뻗어나간다
	return solve(step + 1, minPuzzle);
	// }
}

//현재 퍼즐에서 답과 다른 칸의 개수 반환
int isNotSorted(int (*puzzle)[5])
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