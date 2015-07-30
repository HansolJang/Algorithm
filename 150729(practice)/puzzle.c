/*
https://www.acmicpc.net/problem/1525
*/
#include <stdio.h>
#include <memory.h>

#define INF 987654321

int puzzle[5][5];
int step = 0;
int minStep = INF;

int dirR[4] = {0, 0, 1, -1};
int dirC[4] = {1, -1, 0, 0};

bool isSorted(int (*puzzle)[5]);
void solve(int step, int (*puzzle)[5], int xrow, int xcol);

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

	solve(0, puzzle, -1, -1);

	if(minStep == INF)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", minStep);
	}

	return 0;
}

void solve(int step, int (*puzzle)[5], int xrow, int xcol)
{
	printf("call %d  0row : %d  0col: %d\n", step, xrow, xcol);
	
	if(step == 5){
		return;
	}
	
	if(isSorted(puzzle))
	{
		printf("----------finish\n");
		if(step < minStep)
		{
			minStep = step;
		}
		return;
	}

	for(int i=1; i<4; i++)
	{
		for(int j=1; j<4; j++)
		{	
			//0의 위치
			if(puzzle[i][j] == 0)
			{
				//상하좌우검색
				for(int k=0; k<4; k++)
				{
					int row = i + dirR[k];
					int col = j + dirC[k];

					//이전의 0의 위치를 비교하여 직전으로 되돌아 가지 않음
					if(puzzle[row][col] > 0 && !(row == xrow && col == xcol))
					{
						printf("step : %d, row %d col %d\n", step, row, col);
						puzzle[i][j] = puzzle[row][col];  //이동
						puzzle[row][col] = 0;

						//현재 바꾸기 전의 0의 위치 전송
						solve(step + 1, puzzle, i, j);

						puzzle[row][col] = puzzle[i][j];  //되돌리기
						puzzle[i][j] = 0;
					}
				}
			}
		}
	}
}

bool isSorted(int (*puzzle)[5])
{
	int row = 1;
	int col = 1;
	for(int i=1; i<10; i++)
	{
		if(puzzle[row][col] != i)
		{
			//가장 마지막칸
			if(row == 3 && col == 3 && puzzle[row][col] == 0){
				return true;
			}
			return false;
		} 
		col++;
		if(col % 3 == 1)
		{
			row++;
			col = 1;
		}
	}
}