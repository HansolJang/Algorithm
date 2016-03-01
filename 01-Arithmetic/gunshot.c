#include <stdio.h>

int main() {
	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int i;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		int board[6][6];
		int max = 0;
		int val = 0;
		for(i=0; i<6; i++) {
			for(int j=0; j<6; j++) {
				board[i][j] = -1;
			}
		}
		printf("#testcase%d\n",itr+1);
		for(i=0; i<6; i++) {
			scanf("%d %d %d %d %d %d\n", &board[i][0], &board[i][1], &board[i][2], &board[i][3], &board[i][4], &board[i][5]);
		}

		for(i=0; i<6; i++) {
			for(int j=0; j<6; j++) {
				val = 0;
				val += board[i][j];
				if(i+1 < 6) {
					val += board[i+1][j];
				}
				if(i-1 > -1) {
					val += board[i-1][j];
				}
				if(j+1 < 6) {
					val += board[i][j+1];
				}
				if(j-1 > -1) {
					val += board[i][j-1];
				}
				
				if(val > max) max = val;
			}
		}
		printf("%d\n", max);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 
}