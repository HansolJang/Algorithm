#include <stdio.h>
#include <memory.h>

#define SIZE 555
#define INF 987654321

int N;
int s_file[SIZE];
// 해당 인덱스까지의 최소 비용 저장
int cache[SIZE];

int min(int a, int b)
{
	if(a > b)
		return b;
	else
		return a;
}

int solve(int idx);

int main()
{
	int nCount;
	int itr;

	scanf("%d", &nCount);
	for(itr=0; itr<nCount; itr++)
	{
		memset(cache, -1, sizeof(cache));
		memset(s_file, 0, sizeof(s_file));
		scanf("%d", &N);
		for(int i=0; i<N; i++)
		{
			scanf("%d", &s_file[i]);
		}
		solve(3);

		for(int i=0; i<N; i++)
			printf("[%d] %d\n", i, cache[i]);
	}
}

/*
0 ~ n-1 까지 파일 합치기
*/
int solve(int idx)
{	
	if(idx == 0)
		return s_file[0];
	if(idx == 1)
		return s_file[0] + s_file[1];
	if(idx == N)
		return 0;
	if(idx > N)
		return INF;

	int& ret = cache[idx];

	if(ret != -1)
		return ret;

	ret = 0;
	ret = min(solve(idx-1) + s_file[idx], 
		solve(idx-2) + s_file[idx-1] + s_file[idx]); 
	return ret;
}