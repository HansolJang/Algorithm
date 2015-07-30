#include <stdio.h>

int main() {
	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		printf("#testcase%d\n",itr+1);
		char input[1000];
		for(int i=0; i<1000; i++) {
			input[i] = -1;
		}
		scanf("%s", &input);
		//65~90 대문자
		//97~122 소문자
		for(int i=0; i<1000; i++) {
			// printf("%d\n", input[i]);
			if(input[i] < 0) {
				break;
			} else {
				if(input[i] < 91) {
					input[i] += 32;	
				} else {
					input[i] -= 32;
				}
			}
			printf("%c", input[i]);
		}
		printf("\n");
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 
}