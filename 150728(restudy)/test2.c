/*

VC, GCC에서 사용

*/

#include <stdio.h>

int P;
int N[4];
int order[1111];

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		for(int i=0; i<4; i++)
		{
			N[i] = 0;
		}
		printf("#testcase%d\n",itr+1);

		scanf("%1d %d", &N, &P);

		printf("4\n");
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}