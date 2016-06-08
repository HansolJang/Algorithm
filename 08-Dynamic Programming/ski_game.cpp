/*

VC, GCC에서 사용

*/

#include <stdio.h>
#include <memory.h>

#define MAX(a,b) (a) > (b) ? (a) : (b)

int N;
int map[555][555];
int cache[555][555];
int ans;

int dirR[4] = {0, 0, 1, -1};
int dirC[4] = {1, -1, 0, 0};

int solve(int row, int col);

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		memset(map, -1, sizeof(map));
		memset(cache, -1, sizeof(cache));
		ans = 0;

		printf("#testcase%d\n",itr+1);
		scanf("%d", &N);
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N; j++)
			{
				ans = (MAX(ans, solve(i, j)));
			}
		}
		printf("%d\n", ans);

		// printf("%d\n", solve(1,1));
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}


//(row, col)위치에서 시작할때의 최대값 반환
int solve(int row, int col)
{
	if(map[row][col] == -1)
	{
		return 0;
	}

	int& ret = cache[row][col];
	if(ret != -1)
		return ret;

	ret = 0;

	for(int i=0; i<4; i++)
	{
		int nrow = row + dirR[i];
		int ncol = col + dirC[i];

		if(map[nrow][ncol] != -1 && map[row][col] > map[nrow][ncol])
		{
			ret = (MAX(ret, map[row][col] - map[nrow][ncol] + solve(nrow, ncol)));
		}
	}

	return ret;

}


/*
행과 열의 개수가 모두 n인 스키 게임용 보드가 있다. 
각 행은 크기가 같은 개의 셀로 나뉘어 있고, 각 열도 마찬가지로 크기가 같은 개의 셀로 나뉘어 있다. 
보드에는 모두 개의 셀이 있고, 각 셀의 높이는 미리 정해져 있다. 아래 그림은 스키 게임을 위한 보드의 예를 보여준다. 
셀에 들어있는 숫자는 해당 셀의 높이를 나타낸다.

 

이 게임은 다음과 같이 진행된다. 먼저 스키 보드에 있는 임의의 한 셀을 선택하여 그 셀에 로봇 스키어를 둔다. 
이 스키어를 동/서/남/북 방향으로 인접하면서 높이가 더 낮은 셀로 이동시킬 수 있는데, 
이동시킬 때마다 두 셀의 높이 차이만큼의 점수를 득점한다. 
인접하면서 높이가 낮은 셀로 이동을 계속하면서 얻은 점수를 누적하여 최종적으로 누적된 점수가 더 큰 사람이 승리한다.

예를 들어, 위 그림의 게임 보드에서 높이가 10인 1행 3열에, 
즉 셀 (1,3)에 스키어를 둔 다음 높이가 6인 셀 (2,3), 높이가 1인 셀 (2,4)로 이동하면 총 4+5점을 획득한다. 
이 보다 높은 점수를 얻을 수 없으므로 9점이 최고점이 된다. 
높이가 11인 셀 (4,4)에 시작하더라도 6점밖에 얻을 수 없다. (높이가 같은 셀로는 이동할 수 없음에 유의한다.)

주어진 스키 게임 보드에서 얻을 수 있는 최대 점수를 계산하는 프로그램을 작성하시오. 


[입력]
첫 줄에 테스트 케이스의 개수 T ( T <= 10 ) 가 주어진다. 각 테스트 케이스의 첫줄마다 양의 정수 n이 주어진다.
 ( 0< n <= 500)
다음 줄부터 n만큼의 줄 만큼 셀의 높이가 입력된다.

[출력]
각 테스트 케이스당 한 줄을 출력한다. 한 줄에 주어진 스키 게임 보드에서 얻을 수 있는 최고점을 출력한다.

( 중요! 테스트 케이스 개수마다 #testcase번호를 출력 후 정답 출력 )

[입출력 예]

입력
1
4
1 6 10 3
5 5 6 1
5 7 2 3
11 5 7 4

출력
#testcase1
9
*/