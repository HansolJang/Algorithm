/*
https://www.acmicpc.net/problem/2565
*/
#include <stdio.h>
#include <memory.h>

#define ABS(a) (a) > 0 ? (a) : -(a)
#define MAX(a,b) (a) > (b) ? (a) : (b)

int N;
int wire[555];
int mincnt = 987654321;

//전기줄들이 교차되어 있는지 아닌지 여부 반환
bool is_crossed(int* wire);
void solve(int cnt, int* wire);

int main()
{
	memset(wire, -1, sizeof(wire));
	scanf("%d", &N);
	int a, b;
	
	for(int i=1; i<=N; i++)
	{
		scanf("%d %d", &a, &b);
		wire[a] = b;
	}

	solve(0, wire);

	printf("%d\n", mincnt);

	return 0;
}

//지운 전기줄 갯수, 현재 지울 인덱스, 모든 전깃줄 정보
void solve(int cnt, int* wire)
{	
	if(!is_crossed(wire))
	{
		// printf("%d\n", cnt);
		if(mincnt > cnt)
		{
			mincnt = cnt;
		}
		return;
	}

	for(int i=1; i<=N; i++)
	{
		if(wire[i] != -1)
		{
			int cpy = wire[i];
			wire[i] = -1;
			solve(cnt + 1, wire);
			wire[i] = cpy;
		}
	}
}

bool is_crossed(int* wire)
{
	bool is_cross = false;
	int pre = -1;
	for(int i=1; i<=N; i++)
	{	
		// -1이면 사용하지 않는 전기줄 번호
		if(wire[i] != -1)
		{
			if(pre == -1)
			{
				pre = i;
			} 
			else
			{
				if(wire[pre] > wire[i])
				{
					// return pre;
					is_cross = true;
					break;
				}
			}
		}
	}

	// return -1;
	return is_cross;
}