/*

VC, GCC에서 사용

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int a, b, k;
	int *r;
	int *s; 
	int *p;
	int *t;
	int poscnt = 0;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		printf("#testcase%d\n",itr+1);
		scanf("%d %d %d", &a, &b, &k);
		int board[a+1][b+1];
		for(int i=0; i<a+1; i++) {
			for(int j=0; j<b+1; j++) {
				board[i][j] = 0;
			}
		}
		r = (int *)malloc(sizeof(int) * k);
		s = (int *)malloc(sizeof(int) * k);
		p = (int *)malloc(sizeof(int) * k);
		t = (int *)malloc(sizeof(int) * k);
		// int row[a+1];
		// int col[b+1];
		// int rowcnt = 0;
		// int colcnt = 0;
		int tcnt = 0;  // 폭탄던진 횟수중 보석이 안에 있는 횟수
		// for(int i=0; i<10; i++) {
		// 	row[i] = 0;
		// 	col[i] = 0;
		// }
		int beginr;
		int endr;
		int beginc;
		int endc;

		for(int i=0; i<k; i++) {
			scanf("%d %d %d %d", &r[i], &s[i], &p[i], &t[i]);
			int h = (int)(p[i]/2);
			beginr = r[i] - h;
			if(beginr < 1) {
				beginr = 1;
			}
			endr = r[i] + h;
			if(endr > a) {
				endr = a;
			}
			beginc = s[i] - h;
			if(beginc < 1) {
				beginc = 1;
			}
			endc = s[i] + h;
			if(endc > b) {
				endc = b;
			}

			if(t[i] == 1) {
				tcnt++;
				for(int j=beginr; j<endr+1; j++) {
					for(int k=beginc; k<endc+1; k++) {
						if(board[j][k] == -1) {
							continue;
						} else {
							board[j][k]++;
						}
					}
				}
			} else {
				for(int j=beginr; j<endr+1; j++) {
					for(int k=beginc; k<endc+1; k++) {
						board[j][k] = -1;
					}
				}
			}
			// else {
			// 	row[tr]--;
			// 	col[tc]--;
			// 	for(int j=0; j<h; j++) {
			// 		row[--tr]--;
			// 		col[--tc]--;
			// 	}
			// 	for(int j=0; j<h; j++) {
			// 		row[++r[i]]--;
			// 		col[++s[i]]--;
			// 	}
			// }
		}

		for(int i=0; i<a+1; i++) {
			for(int j=0; j<b+1; j++) {
				printf("%d ", board[i][j]);
				if(board[i][j] == tcnt) {
					poscnt++;
				}
			}
			printf("\n");
		}

		printf("%d\n", poscnt);

		free(r);
		free(s);
		free(p);
		free(t);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}