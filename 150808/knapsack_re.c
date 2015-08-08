/*
http://www.jungol.co.kr/problem.php?ctc=030500&id=1278
*/
#include <stdio.h>
#include <memory.h>

#define INF 987654321
#define MAX(a,b) (a) > (b) ? (a) : (b)
#define NSIZE 1111
#define WSIZE 11111

int N, W;
int j_weight[NSIZE];
int j_value[NSIZE];
int cache[NSIZE][WSIZE];

int solve(int idx, int leftWeight);

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d %d", &N, &W);
	for(int i=0; i<N; i++)
	{
		scanf("%d %d", &j_weight[i], &j_value[i]);
	}
	printf("%d\n", solve(0, W));
	return 0;
}

//idx번째에서 시작하고 leftWeight를 넘지 않는 최대 가치의 합 리턴
int solve(int idx, int leftWeight)
{
	if(leftWeight < 0)
	{
		return -INF;
	}

	if(idx == N)
	{
		return 0;
	}

	int& ret = cache[idx][leftWeight];
	if(ret != -1)
	{
		return ret;
	}

	ret = -INF;
	//선택안함
	ret = (MAX(ret, solve(idx + 1, leftWeight)));
	//선택
	ret = (MAX(ret, j_value[idx] + solve(idx + 1, leftWeight - j_weight[idx])));
	return ret;
}