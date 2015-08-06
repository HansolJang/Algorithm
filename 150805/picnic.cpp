/*
https://algospot.com/judge/problem/read/PICNIC
*/
#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int N, M;
bool mate[11][11];
bool used[11];
int ans;

int solve(int order, bool* used);

int main()
{
	int itr;
	int nCount;
	scanf("%d", &nCount);
	for(itr=0; itr<nCount; itr++)
	{
		memset(mate, 0, sizeof(mate));
		memset(used, 0, sizeof(used));
		ans = 0;

		scanf("%d %d", &N, &M);
		int a, b;
		for(int i=0; i<M; i++)
		{
			scanf("%d %d", &a, &b);
			mate[a][b] = true;
			mate[b][a] = true;
		}

		printf("%d\n", solve(0, used));
	}
	return 0;
}

//몇번째 친구쌍을 고를 차례이고, 지금까지 맺어준 친구정보를 배열로 받을 때
//가능한 경우의 수 리턴 
int solve(int order, bool* used)
{
	// printf("-----solve call order : %d\n", order);
	if(order == N)
	{
		return 1;
	}

	int ret = 0;
	//이미 짝이 되었음
	if(used[order] == true)
	{
		ret += solve(order + 1, used);
	}
	//새 짝을 찾아야함
	else
	{	
		for(int i=0; i<N; i++)
		{
			if(mate[order][i] == true && used[i] == false)
			{
				used[order] = true;
				used[i] = true;
				ret += solve(order + 1, used);
				used[i] = false;
				used[order] = false;	
			}
		}
	}

	return ret;
}