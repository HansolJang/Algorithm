#include <stdio.h>

int main() {
	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int opennum;
	int lockernum;
	int limit;
	int isOpen = true;
	int i;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		isOpen = true;
		printf("#testcase%d\n",itr+1);
		scanf("%d %d", &opennum, &lockernum);

		if(opennum > lockernum) limit = lockernum;
		else limit = opennum;

		for(i=2; i<opennum+1; i++) {
			if(lockernum%i == 0) isOpen = !isOpen;
		}
		printf("%d\n", isOpen);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 
}