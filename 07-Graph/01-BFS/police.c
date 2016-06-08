/*

VC, GCC에서 사용

*/

#include <stdio.h>

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int n, k;
	int i;
	int arr[222222];
	int three[15] = {1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969};
	int front;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		scanf("%d %d", &n, &k);
		int cnt = 0;
		arr[0] = n;
		front = 0;
		while(1) {
			arr[++cnt] = arr[front] - 1;
			if(arr[cnt] == k) break;
			else if(cnt == 222221) break;
			arr[++cnt] = arr[front] + 1;
			if(arr[cnt] == k) break;
			else if(cnt == 222221) break;
			arr[++cnt] = arr[front] * 2;
			if(arr[cnt] == k) break;
			else if(cnt == 222221) break;
			front++;
		}

		int sum = 0;
		for(i=0; i<15; i++) {
			sum += three[i];
			if(sum > cnt) break;
		}
		printf("%d\n", cnt);
		if(cnt == 222221) printf("fail\n");
		else printf("%d\n", i);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}