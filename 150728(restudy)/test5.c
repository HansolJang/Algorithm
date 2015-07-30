/*

VC, GCC에서 사용

*/

#include <stdio.h>

#define SIZE 15

int map[SIZE][SIZE];
bool visited[15];
int N;

int solve(int order, int from);
int min(int a, int b)
{
	if(a > b) return b;
	else return a;
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		//초기화
		for(int i=0; i<SIZE; i++)
		{
			for(int j=0; j<SIZE; j++)
			{
				map[i][j] = 0;
				cache[i][j] = -1;
			}
			visited[i] = false;
		}
		printf("#testcase%d\n",itr+1);

		scanf("%d", &N);

		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		visited[1] = true;  //visit

		printf("%d\n", solve(1, 1));

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}

//from 지점에서 몇번째 차례로 가게될때
//최소의 이동경비 반환
int solve(int order, int from)
{
	// printf("-------------%d %d\n", order, from);
	if(order == N)
	{	

		// printf("go home from %d to: %d \n", from, map[from][1]);
		//마지막은 무조건 집으로
		if(map[from][1] == 0)
		{
			return INF;
		}
		return map[from][1];
	}

	int ret = INF;

	for(int i=1; i<=N; i++)
	{	
		// printf("visited %d : %d\n", i, visited[i]);
		if(visited[i] == false) 
		{	
			visited[i] = true;
			// printf("next -> %d\n", i);
			ret = min(ret, map[from][i] + solve(order + 1, i));
			visited[i] = false;
		} 
	}

	return ret;
}