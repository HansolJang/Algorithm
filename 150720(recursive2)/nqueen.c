/*

VC, GCC에서 사용

*/

#include <stdio.h>

int n;
int board[12][12] = {};
int acnt;  //답의 갯수
int i, j;

int abs(int a) {
	if(a > 0) return a;
	else return -a;
}

bool is_possible(int row, int col) {
	int i,j;
	//가로
	for(i=0; i<n; i++) {
		if(board[row][i] == 1) {
			return false;
		}
	}

	//세로
	for(i=0; i<n; i++) {
		if(board[i][col] == 1) {
			return false;
		}
	}
	
	//대각선
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if(abs(row-i) == abs(col-j) && board[i][j] == 1) {
				return false;
			}
		}
	}

	return true;

}

void n_queen(int row) {
	if(row == n) {
		acnt++;
		for(j=0; j<n; j++) {
			for(int k=0; k<n; k++) {
				printf("%d ", board[j][k]);
			}
			printf("\n");
		}
		printf("\n");
		return;
	}

	for(i=0; i<n; i++) {
		if(is_possible(row, i)) {
			board[row][i] = 1;
			n_queen(row + 1);
			board[row][i] = 0;
		}
	}
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{	
		acnt = 0;
		printf("#testcase%d\n",itr+1);
		scanf("%d", &n);

		for(i=0; i<n; i++) {
			for(j=0; j<n; j++) {
				board[i][j] = 0;
			}
		}
		n_queen(0);
		printf("%d\n", acnt);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}