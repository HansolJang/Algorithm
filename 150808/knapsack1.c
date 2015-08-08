/*
http://www.jungol.co.kr/problem.php?id=1077
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
int scnt, ccnt;

int solve(int idx, int leftWeight);

int main()
{
	memset(cache, -1, sizeof(cache));
	scnt = 0;
	ccnt = 0;
	scanf("%d %d", &N, &W);
	for(int i=0; i<N; i++)
	{
		scanf("%d %d", &j_weight[i], &j_value[i]);
	}
	printf("%d\n", solve(0, W));
	printf("sovle call cnt : %d  caching cnt : %d   rate : %.2f\n", scnt, ccnt, (double) ccnt / scnt);
	return 0;
}

//idx번째에서 시작하고 leftWeight를 넘지 않는 최대 가치의 합 리턴
int solve(int idx, int leftWeight)
{
	scnt++;
	if(idx == N)
	{
		return 0;
	}

	int& ret = cache[idx][leftWeight];
	if(ret != -1)
	{
		ccnt++;
		return ret;
	}

	ret = -INF;

	//idx번째 보석을 몇개 선택할건지 결정
	for(int cnt=0;; cnt++)
	{
		if(leftWeight - j_weight[idx] * cnt >= 0)
		{
			ret = (MAX(ret, j_value[idx] * cnt + solve(idx + 1, leftWeight - j_weight[idx] * cnt)));
		}
		else
			break;
	}

	return ret;
}

/*
2 40
5 110
10 200
3 50
7 150
8 180
15 300
17 350
1 20
20 500
4 45
6 115
11 200
3 50
9 150
12 180
16 300
18 350
19 400 
21 500

*/