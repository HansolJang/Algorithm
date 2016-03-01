/*
https://www.acmicpc.net/problem/1495
*/
#include <stdio.h>
#include <memory.h>

#define MAX(a,b) (a) > (b) ? (a) : (b)
#define INF 987654321
#define SIZE 111

int N, S, M;
int vol[SIZE] = {};
int maxV = -INF;
void solve(int order, int v);

int main()
{
	scanf("%d %d %d", &N, &S, &M);
	for(int i=1; i<=N; i++)
	{
		scanf("%d", &vol[i]);
	}

	solve(1, S);

	if(maxV == -INF)
		printf("-1\n");
	else
		printf("%d\n", maxV);	
	return 0;
}

//해당 곡의 순서에 대한 볼륨의 가짓수 완전탐색
void solve(int order, int v)
{
	printf("%d volume : %d\n", order, v);
	if(order == N + 1)
	{
		if(maxV < v)
		{
			maxV = v;
		}
		return;
	}

	if(v + vol[order] <= M)
	{
		solve(order + 1, v + vol[order]);
	}

	if(v - vol[order] >= 0)
	{
		solve(order + 1, v - vol[order]);
	}

}
