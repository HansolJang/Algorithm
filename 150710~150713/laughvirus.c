/*

VC, GCC에서 사용

*/

#include <stdio.h>

int check(int* arr, int x, int y, int row, int col, int* second, int* pcnt, int cnt);

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int row, col;
	int i, j;
	int bx, by;
	int cnt;
	int personcnt;
	int* pcnt = &personcnt;
	int second; //시간 경과
	int* ps = &second;


	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		int isEnd = false;
		second = 0;
		cnt = 0;
		personcnt = 0;
		printf("#testcase%d\n",itr+1);
		scanf("%d %d", &row, &col);
		int board[row][col];
		int (*pb)[col] = board;  //*pb = board[0]
		for(i=0; i<row; i++) {
			for(j=0; j<col; j++) {
				scanf("%d ", &board[i][j]);
				cnt++;
			}
		}
		scanf("%d %d", &bx, &by);
		bx -= 1; //0부터 시작
		by -= 1;

		(*ps)++;
			// 1일때 사람이 있으면 1 없으면 0 이므로 그대로 둠
		check(&pb, bx, by, row, col, &ps, &pcnt, cnt);
		printf("%d\n", *ps);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}

int check(int* arr, int x, int y, int row, int col, int* second, int* pcnt, int cnt) {
	//4방향을 확인하고 재귀호출
	if(*pcnt == cnt) return *second;
	else {
		second++;
		if(x-1 > -1) {
			if((*arr+(x-1))[y] == 1) {
				arr[x-1][y] = *second;
				(*pcnt)++;
			}
			check(&arr, x-1, y, row, col, &second, &pcnt, cnt);
		}
		if(x+1 < row) {
			if(arr[x+1][y] == 1) {
				arr[x+1][y] = *second;
				(*pcnt)++;
			}
			check(&arr, x+1, y, row, col, &second, &pcnt, cnt);
		}
		if(y-1 > -1) {
			if(arr[x][y-1] == 1) {
				arr[x][y-1] = *second;
				(*pcnt)++;
			}
			check(&arr, x, y-1, row, col, &second, &pcnt, cnt);
		}
		if(y+1 < col) {
			if(arr[x][y+1] == 1) {
				arr[x][y+1] = *second;
				(*pcnt)++;
			}
			check(&arr, x, y+1, row, col, &second, &pcnt, cnt);
		}
	}
}