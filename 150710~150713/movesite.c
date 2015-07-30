/*

VC, GCC에서 사용

*/

#include <stdio.h>
#include <string.h>

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	char site[111][77];
	char oper[10];
	int top;
	int end = 0;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{	
		top = 0;
		printf("#testcase%d\n",itr+1);
		for(int i=0; i<112; i++) {
			site[i][0] = -1;
		}
		strcpy(site[top], "https://secmem.org/");

		while(1) {
			scanf("%s",oper);
			if(!strcmp(oper, "QUIT")) {
				break;
			} else if(!strcmp(oper, "VISIT")) {
				scanf("%s", site[++top]);
				scanf("\n");
			}else if (!strcmp(oper, "BACKWARD")) {
				if(top-1 < 0) {
					printf("Ignored\n");
				} else {
					printf("%s\n", site[--top]);
				}
			} else if (!strcmp(oper, "FORWARD")) {
				if(site[top+1][0] == -1) {
					printf("Ignored\n");
				} else {
					printf("%s\n", site[++top]);
				}
			} else {
				printf("wrong operand\n");
			}
		}
		
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}