/*

VC, GCC에서 사용

*/

#include <stdio.h>

#define NUM 1000000007

int N, K;

int solve(int idx, int leftCandy, int xcnt);

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		scanf("%d %d", &N, &K);

		printf("%d\n", solve(1, N, 1));
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 
}

//idx번째에 줄 사탕 개수를 선택할 차례이고 현재 남은 사탕이 leftCandy개이고
//직전 아이에게 준 사탕의 개수가 xcnt일 때
//가능한 경우의 수 반환
int solve(int idx, int leftCandy, int xcnt)
{
	// printf("idx : %d   leftCandy : %d\n", idx, leftCandy);
	if(idx == K+1)
	{
		if(leftCandy == 0)
		{
			// printf("-----------------------answer\n");
			return 1;
		}
		else 
			return 0;
	}

	for(int cnt=xcnt; cnt<=leftCandy; cnt++)
	{
		ret += solve(idx + 1, leftCandy - cnt, cnt);
	}

	return ret % NUM;
}