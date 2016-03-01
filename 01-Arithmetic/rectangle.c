/*

VC, GCC에서 사용

*/

#include <stdio.h>
#include <memory.h>

int paper[111][111];
int point[111][2];

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int num;
	int area;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		memset(paper, -1, sizeof(paper));
		printf("#testcase%d\n",itr+1);
		scanf("%d", &num);
		for(int i=0; i<num; i++){
			scanf("%d %d", &point[i][0], &point[i][1]);
			for(int j=point[i][0]; j<point[i][0]+10; j++) {
				for(int k=point[i][1]; k<point[i][1]+10; k++) {
					paper[j][k] = 1;
				}
			}
		}

		area = 0;
		for(int i=1; i<101; i++) {
			for(int j=1; j<101; j++) {
				if(paper[i][j] == 1) area++;
			}
		}

		printf("%d\n", area);

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}