
#include <stdio.h>

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	//scanf("%d", &nCount);	/* 테스트 케이스 입력 */
	nCount = 1;
	int h;
	int d;
	int r;
	int am;
	
	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		for(int i=100; i<1000; i++) {
			h = (int)i/100;
			d = (int)i/10 - (h*10);
			r = (int)i - (h*100) - (d*10);
			am = h*h*h+d*d*d+r*r*r;
			// printf("%d : %d %d %d %d\n", i, h, d, r, am);

			if(am == i) {
				printf("%d\n", i);
			}
		}

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}