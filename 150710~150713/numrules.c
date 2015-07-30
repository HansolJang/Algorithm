/*

VC, GCC에서 사용

*/

#include <stdio.h>

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int input[5];

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		int d;
		bool isPlus = false;

		printf("#testcase%d\n",itr+1);

		scanf("%d %d %d %d", &input[0], &input[1], &input[2], &input[3]);
		d = input[1] - input[0];

		if(input[2] - input[1] == d) {
			if(input[3] - input[2] == d) isPlus = true;
			else isPlus = false;
		} else isPlus = false;

		if(isPlus) {
			printf("%d %d %d %d %d\n", input[0], input[1], input[2], input[3], input[3] + d);
		} else {
			int r = input[1] / input[0];
			printf("%d %d %d %d %d\n", input[0], input[1], input[2], input[3], input[3]*r);
		}
		printf("\n");

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}