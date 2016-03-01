/*

시간 제한:1초
제곱수일 경우에만 +1, 나머진 +2
8 = 1,2,4,8
이므로 1,2 까지만 세고 *2해주면됨
제곱근까지만 구함
8일 경우 (int)루트8 = 2까지

*/

#include <stdio.h>

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int num;
	int pCount;
	int i = 1;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */
	
	for(itr=0; itr<nCount; itr++)
	{
		pCount = 0;
		i = 1;
		printf("#testcase%d\n",itr+1);
		scanf("%d", &num);
		// for(i=1; i<num+1; i++) {
		// 	if(num % i == 0){
		// 		pCount++;
		// 	}
		// }
		while(1) {
			if(i*i == num) {
				pCount++;
				break;
			} else if (i*i > num) {
				break;
			}else {
				if(num%i == 0) {
					pCount += 2;
				}
			}
			i++;
		}
		printf("%d\n", pCount);
	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 
}