/*

VC, GCC에서 사용

*/

#include <stdio.h>
#include <string.h>

void mt_height(int n) {
	if(n == 1) {
		printf("1");
		return;
	}
	mt_height(n-1);
	printf("%d", n);
	mt_height(n-1);
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int input;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		scanf("%d", &input);
		
		mt_height(input);
		printf("\n");
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}