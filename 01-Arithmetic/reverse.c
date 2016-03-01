/*

VC, GCC에서 사용

*/

#include <stdio.h>

int main() {

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int top;
	char str[22];

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++) {
		printf("#testcase%d\n",itr+1);
		while(1) {
			top = 0;
			for(int i=0; i<22; i++) {
				str[i] = -1;
			}
			scanf("%s", &str);
			if(str[0] == 'E' && str[1] == 'N' && str[2] == 'D' && str[3] == 0) {
				break;
			}
			for(int i=0; i<22; i++) {
				if(str[i] == -1) {
					top = i-1;
					break;
				}
			}
			while(top > 0) {
				printf("%c", str[--top]);
			}
			printf("\n");
		}
	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 
}