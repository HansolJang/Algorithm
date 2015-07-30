/*

VC, GCC에서 사용

*/

#include <stdio.h>

int check(int arr[][100], int x, int y, int row, int col, int second, int pcnt, int cnt);

int main()
{
	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int row, col;
	int i, j;
	int bx, by;
	int cnt;
	int pcnt;
	int second; //시간 경과


	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		int isEnd = false;
		second = 0;
		cnt = 0;
		pcnt = 0;
		printf("#testcase%d\n",itr+1);
		scanf("%d %d", &row, &col);
		int board[row][100];
		for(i=0; i<row; i++) {
			for(j=0; j<col; j++) {
				scanf("%d ", &board[i][j]);
				cnt++;
			}
		}
		scanf("%d %d", &bx, &by);
		bx -= 1; //0부터 시작
		by -= 1;

		second++;
		second = check(board, bx, by, row, col, second, pcnt, cnt);
		printf("%d\n", second);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}

int check(int arr[][100], int x, int y, int row, int col, int second, int pcnt, int cnt) {
	//4방향을 확인하고 재귀호출
	if(pcnt == cnt) {
		for(int i=0; i<row; i++) {
			for(int j=0; j<col; j++) {
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		return second;
	} else if (second == -1) {
		
	}
	else {
		int isEnd = false;
		second++;
		printf("second : %d\n", second);
		if(x-1 > -1) {
			if(arr[x-1][y] == 1) {
				arr[x-1][y] = second;
				(pcnt)++;
				return check(arr, x-1, y, row, col, second, pcnt, cnt);
			}
		}
		if(x+1 < row) {
			if(arr[x+1][y] == 1) {
				arr[x+1][y] = second;
				(pcnt)++;
				return check(arr, x+1, y, row, col, second, pcnt, cnt);
			}
		}
		if(y-1 > -1) {
			if(arr[x][y-1] == 1) {
				arr[x][y-1] = second;
				(pcnt)++;
				return check(arr, x, y-1, row, col, second, pcnt, cnt);
			} 
		}
		if(y+1 < col) {
			if(arr[x][y+1] == 1) {
				arr[x][y+1] = second;
				(pcnt)++;
				return check(arr, x, y+1, row, col, second, pcnt, cnt);
			}
		}
	}
}
