/*

VC, GCC에서 사용

*/

#include <stdio.h>
#include <memory.h>

#define MAX(a,b) (a) > (b) ? (a) : (b)
#define INF 987654321

int C, B;
int basket[25];
int cache[25][36666];
int maxCal;

int solve(int idx, int leftCalories);

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		memset(cache, -1, sizeof(cache));
		printf("#testcase%d\n",itr+1);

		scanf("%d %d", &C, &B);
		for(int i=1; i<=B; i++)
		{
			scanf("%d", &basket[i]);
		}
		maxCal = solve(1, C);

		if(maxCal == -INF)
			printf("0\n");
		else
			printf("%d\n", maxCal);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}

//idx 번째에서 leftCalories만큼 남았을때 선택할 수 있는 최대의 칼로리 반환
int solve(int idx, int leftCalories)
{
	if(idx == B + 1)
	{
		if(leftCalories >= 0)
		{
			// printf("left : %d\n", leftCalories);
			return 0;
		}
		else
			return -INF;
	}

	int& ret = cache[idx][leftCalories];
	if(ret != -1)
	{
		// printf("------caching\n");
		return ret;
	}

	ret = -INF;
	ret = (MAX(ret, solve(idx + 1, leftCalories))); //선택안함
	if(leftCalories - basket[idx] >= 0)
	{
		ret = (MAX(ret, basket[idx] + solve(idx + 1, leftCalories - basket[idx])));  //선택
	}
	return ret;
}


/*
 경우는 다이어트를 하고 있다. 하루 칼로리 양 C를 정하여 이를 초과하면 먹지 않기로 하였다. 
 그런데, 영훈이가 감자튀김이 든 B개의 바구니를 경우에게 주어 다이어트를 망치려고 하고 있다. 
 각 바구니 안에는 일정한 양의 칼로리를 가지고 있다.
 여러분은 하루 칼로리 양 C가 초과하지 않는 상태에서 각각의 바구니 안에 든 음식의 최대 값을 찾도록 도와주는 것이다.

입력
 입력의 첫 줄에는 테스트 케이스의 수가 주어진다.
 각 테스트 케이스마다 다음과 같이 주어진다.
 - 첫번째 줄에는 칼로리의 한도 C (0 <= C <= 35000)와 바구니의 수 B(2 <= B <= 21)가 주어진다.
 - 두번째 줄에는 B개의 바구니에 들어있는 각각의 음식의 칼로리가 주어진다.
(각각의 음식의 칼로리 <= 100)
출력
 한도를 초과하지 않고 먹을 수 있는 최대 칼로리 양이다.
(모든 경우의 수가 칼로리의 한도를 초과하여 아무것도 선택할 수 없는 경우 0을 출력한다.)

입력 예시
1
40 6
7 13 17 19 29 31

15333 13
5687 488 8584 8098 3853 5576 5159 10577 14383 1841 4335 1922 12746
15329

출력 예시
#testcase1
39
*/