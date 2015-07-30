/*

VC, GCC에서 사용

*/

#include <stdio.h>
#include <memory.h>

typedef struct point{
	int row;
	int col;
	int time;
}point;

int board[111][111];
//큐 배열은 더 넉넉히 잡기!
point queue[11111];

point next_point(point p) {
	point res;
	//up
	if(board[p.row-1][p.col] == 1) {
		res.row = p.row - 1;
		res.col = p.col;
		res.time = p.time + 1;
		return res;
	}
	//down
	if(board[p.row+1][p.col] == 1) {
		res.row = p.row + 1;
		res.col = p.col;
		res.time = p.time + 1;
		return res;
	}
	//left
	if(board[p.row][p.col-1] == 1) {
		res.row = p.row;
		res.col = p.col - 1;
		res.time = p.time + 1;
		return res;
	}
	//right
	if(board[p.row][p.col+1] == 1) {
		res.row = p.row;
		res.col = p.col + 1;
		res.time = p.time + 1;
		return res;
	}
	res.row = -1;
	res.col = -1;
	res.time = -1;
	return res;
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{	
		int row, col;
		int bx, by;
		int front = 0;
		int rear = 0;
		int cnt = 0;
		int kill_cnt = 0;

		//map초기화
		memset(board, -1, sizeof(board));
		//큐초기화
		for(int i=0; i<11111; i++) {
			queue[i].row = -1;
		}

		printf("#testcase%d\n",itr+1);

		scanf("%d %d", &col, &row);
		for(int i=1; i<row+1; i++) {
			for(int j=1; j<col+1; j++) {
				scanf("%1d", &board[i][j]);
				// board[i][j] = 1;
				if(board[i][j] == 1) cnt++;
			}
		}
		scanf("%d %d", &bx, &by);
		// printf("%d\n", cnt);

		point p;
		p.row = by;
		p.col = bx;
		p.time = 3;

		board[p.row][p.col] = 3;
		kill_cnt++;

		queue[rear++] = p;

		while(!(front > rear)) {
			point pfront = queue[front];
			point np = next_point(pfront);
			// printf("front row: %d col:%d time: %d\n", pfront.row, pfront.col, pfront.time);
			// printf("np row: %d col:%d time: %d\n", np.row, np.col, np.time);
			while(np.row != -1) {
				queue[rear++] = np;
				board[np.row][np.col] = np.time;
				kill_cnt++;
				// printf("%d\n", kill_cnt);
				np = next_point(pfront);
				// printf("np row: %d col:%d time: %d\n", np.row, np.col, np.time);
			}

			// for(int i=1; i<row+1; i++) {
			// 	for(int j=1; j<col+1; j++) {
			// 		printf("%d", board[i][j]);
			// 	}
			// 	printf("\n");
			// }
			// printf("\n");

			front++;
		}
		printf("%d %d\n", queue[rear-1].time, cnt - kill_cnt);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}

/*

10 10
0000000000
0000010001
0000010001
0001110001
0011011001
0011010001
0011111000
0000001100
0000001000
0000001000
3 6
-> 11 5

7 8
0000001
0011001
0000100
1001111
1110011
0011100
0011100
0001000
3 5
-> 7 11

*/