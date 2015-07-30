/*

VC, GCC에서 사용

*/

#include <stdio.h>
#include <stdlib.h>

char input[111];
int N; //add
int M; //position
char password[4];

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int cnt, pcnt;
	int idx, passcnt;
	int i, j;
	bool is_err;
	int p[4];

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		scanf("%s %d %d", &input, &N, &M);
		cnt = 0;  // - 개수
		pcnt = 0; // - 나오기 직전까지의 숫자개수
		is_err = false;
		for(i=0; i<111; i++) {
			if(input[i] == 0) {
				if(cnt < M) {
					idx = i;
					passcnt = pcnt;
				}
				break;
			}
			if(input[i] == '-') {
				cnt++;
				if(pcnt > 4) {
					is_err = true;
					break;
				}
				if(cnt == M) {
					//저장
					idx = i;
					passcnt = pcnt;
				}
				pcnt = 0;
			} else {
				pcnt++;
			}
		}

		if(!is_err) {
			// printf("%d %d\n", idx, passcnt);
			for(j=0; j<passcnt; j++) {
				password[3-j] = input[--idx];
				// printf("%c %c\n", input[idx], password[3-j]);
			}

			for(i=0; i<4; i++) {
				if(!(password[i] > 48 && password[i] < 58)) {
					password[i] = '0';
				} 
			}
			int pass = atoi(password);
			// printf("%d\n", pass);

			p[0] = ((int)pass / 1000 + N) % 10;
			p[1] = (((int) pass / 100 - (int)(pass/1000)*10) + N) % 10;
			p[2] = ((pass%100 / 10) + N) % 10;
			p[3] = (pass%10 + N) % 10;
		}

		if(is_err) {
			printf("INPUT ERROR!\n");
		} else {
			for(j=0; j<4; j++) {
				printf("%d", p[j]);
			}
			printf("\n");
		}
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}