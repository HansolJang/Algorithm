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

	int ret = 0;

	for(int cnt=xcnt; cnt<=leftCandy; cnt++)
	{
		ret += solve(idx + 1, leftCandy - cnt, cnt);
	}

	return ret % NUM;
}

/*
손승하 운영자는 처음으로 미국에 있는 고향친구를 만나기 위해 해외여행을 떠났다. 
마침 친구집에 도착한 다음 날이 할로윈데이였다!!

할로윈데이에는 찾아오는 아이들에게 사탕을 나눠주는 전통이 있다.
신난 손승하 운영자는 사탕가게에서 아이들에게 나눠줄 N개의 사탕을 구매하였다.

할로윈데이 당일. 찾아올 아이들에게 사탕을 나눠줄 생각에 즐거워 하고 있는 
손승하 운영자에게 친구가 새로운 사실을 말해줬다. 이 지역에 아이들은 자신이 앞에 사탕을 받은 아이보다 
사탕의 수가 적게 받는 것을 매우 싫어한다는 것이다.

그러나 손승하 운영자가 구매한 사탕의 수는 N개이기에 K명의 아이들에게 나눠주기 위해선 잘 생각해야 한다. 
이 때 아이들이 총 K명이 방문할 것을 알게 된 손승하 운영자는 미리 사탕을 나눠줄 경우의 수를 계산해 놓고싶다.

손승하 운영자를 도와 사탕을 나눠줄 수 있는 프로그램을 만들어보자.

예를 들어 사탕 N = 5 이고, K = 3 이면,

(1,1,3) , (1,2,2) 이렇게 두 가지 경우밖에 없다.
(3,1,1), (2,1,2) 같은 경우는 뒤에 사탕은 받은 아이가 앞 아이보다 적게 받으므로 경우의 수에 포함되지 않는다.


[입력]
첫번째 줄 테스트 케이스 T입력
각 테스트케이스 첫 줄에는 사탕의 수 N과 찾아올 아이들 K가 주어진다 
(1<= N,K <= 72)

 [출력]
첫째 줄에 #testcaseN의 형태와 같이 번호를 출력한다
각 테스트케이스마다 아이들에게 사탕을 나눠줄 수 있는 경우의 수를 1,000,000,007로 나눈 나머지를 출력한다.

-입출력 예-

입력
2
8 4
6 2

출력
#testcase1
5
#testcase2
3


*/