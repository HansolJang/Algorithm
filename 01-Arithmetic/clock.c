/*

VC, GCC에서 사용

*/

#include <stdio.h>

int getClockNum(int arr[]) {
	int min;
	int v = 0;
	for(int i=0; i<4; i++) {
		v = 0;
		for(int j=0; j<4; j++) {
			switch(j){
				case 0: 
					v = arr[i] * 1000;
					if(v == 0) return -1;
					break;
				case 1:
					v += arr[(i+1)%4] * 100;
					if(v == 0) return -1;
					break;
				case 2:
					v += arr[(i+2)%4] * 10;
					if(v == 0) return -1;
					break;
				case 3:
					v += arr[(i+3)%4];
					if(v == 0) return -1;
					break;
			}
		}
		if(i == 0) min = v;
		if(min > v) min = v;
	}
	return min;
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int input[4];
	int min;
	int v;

	for(int i=1111; i<100000; i++) {
		
	}


	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		printf("#testcase%d\n",itr+1);
		scanf("%d %d %d %d", &input[0], &input[1], &input[2], &input[3]);

		printf("%d\n", getClockNum(input));
		
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}