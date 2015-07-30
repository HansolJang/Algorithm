#include <stdio.h>

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	char input_str[1000];
	char res_str[1000];
	int rcnt;
	int i;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */
	scanf("\n");

	for(itr=0; itr<nCount; itr++)
	{
		printf("#testcase%d\n",itr+1);
		for(i=0; i<1000; i++) {
			input_str[i] = -1;
			res_str[i] = -1;
		}
		rcnt = 0;
		gets(input_str);
		
		// printf("%s\n", input_str);

		for(i=0; i<1000; i++) {
			if(input_str[i] == 0) {
				res_str[rcnt++] = 0;
				break;
			} else if (input_str[i] != 32) {
				res_str[rcnt++] = input_str[i];
			}
		}

		printf("%s\n", res_str);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}