#include <stdio.h>

typedef struct point{
	int row;
	int col;
	int time;
}point;

int board[111][111]; 
// {
// 	{0, 0, 1, 1, 1, 0, 0},
// 	{1, 1, 1, 1, 0, 1, 0},
// 	{0, 0, 1, 0, 1, 1, 1},
// 	{0, 1, 1, 1, 1, 0, 1},
// 	{0, 0, 1, 0, 1, 1, 0},
// 	{0, 1, 1, 1, 1, 0, 0},
// 	{0, 0, 1, 0, 1, 1, 1},
// 	{0, 0, 0, 0, 1, 0, 0}
// };
point queue[111];
int row, col;
int bx, by;
int front, rear;

point next_point(point input) {
	point p;
	if(board[input.row][input.col+1] == 1) {
		p.row = input.row;
		p.col = input.col + 1;
		p.time = input.time + 1;
		return p;
	}
	if(board[input.row][input.col-1] == 1) {
		p.row = input.row;
		p.col = input.col - 1;
		p.time = input.time + 1;
		return p;
	}
	if(board[input.row+1][input.col] == 1) {
		p.row = input.row + 1;
		p.col = input.col;
		p.time = input.time + 1;
		return p;
	}
	if(board[input.row-1][input.col] == 1) {
		p.row = input.row - 1;
		p.col = input.col;
		p.time = input.time + 1;
		return p;
	}
	p.row = -1;
	p.col = -1;
	p.time = -1;
	return p;
} 


int main()
{

	int itr;
    int nCount;		/* 문제의 테스트 케이스 */
	int t;

    scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		scanf("%d %d", &col, &row);
        for(int i=0; i<row; i++) {
        	for(int j=0; j<col; j++) {
        		scanf("%d", &board[i][j]);
        	}
        }
		scanf("%d %d", &bx, &by);

		front = 0;
		rear = -1;
		t = 1;
		point p;
		p.row = by - 1;
		p.col = bx - 1;
		p.time = t;
		if(board[p.row][p.col] == 1) {
			board[p.row][p.col] = 2;
			queue[++rear] = p;
		}

		while(!(rear < front)) {
			point pfront = queue[front];
			if(pfront.time > t) t = pfront.time;
			point p1;
			while(1) {
				p1 = next_point(pfront);
				if(p1.row == -1) {
					break;
				}
				board[p1.row][p1.col] = p1.time;
				queue[++rear] = p1;
			}

			// for(int i=0; i<row; i++) {
			// 	for(int j=0; j<col; j++) {
			// 		printf("%d ", board[i][j]);
			// 	}
			// 	printf("\n");
			// }
			// printf("\n");

        	front++;  //dequeue
        }

        printf("%d\n", t);
        
    }
    
    return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 
    
}