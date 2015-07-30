/*

VC, GCC에서 사용

*/

#include <stdio.h>

int board[111][111];

void extend_virus(int x, int y, int (*board)[111], int* s, int* max, int row, int col) {
	int up = board[y+1][x];
	int down = board[y-1][x];
	int left = board[y][x-1];
	int right = board[y][x+1];

	if(board[y][x] != 2) {
		board[y][x] = *s; //감염
	}

	// 갈 곳이 없음
	if(up != 1 && down != 1 && left != 1 && right != 1) {
		if(*max < *s) *max = *s;
		return;
	}

	(*s)++;
	//up
	if(y+1 <= row) {
		if(up == 1) {
			extend_virus(x, y+1, board, s, max, row, col);
		}
	}
	//down
	if(y-1 > 0) {
		if(down == 1) {
			extend_virus(x, y-1, board, s, max, row, col);
		}
	}
	//right
	if(x+1 <= col) {
		if(right == 1) {
			extend_virus(x+1, y, board, s, max, row, col);
		}
	}
	//left
	if(x-1 > 0) {
		if(left == 1){
			extend_virus(x-1, y, board, s, max, row, col);
		}
	} 
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int col, row;
	int i, j;
	int s, max;
	int bX, bY;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		scanf("%d %d", &col, &row); //col x row

		for(i=0; i<row; i++) {
			for(j=0; j<col; j++) {
				scanf("%d", &board[i+1][j+1]);
			}
		}
		scanf("%d %d", &bX, &bY);

		s = 1;
		board[bY][bX] = 2;
		max = s;
		extend_virus(bX, bY, board, &s, &max, row, col);
		// for(i=0; i<row; i++) {
		// 	for(j=0; j<col; j++) {
		// 		printf("%d ", board[i+1][j+1]);
		// 	}
		// 	printf("\n");
		// }
		printf("%d\n", max);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}