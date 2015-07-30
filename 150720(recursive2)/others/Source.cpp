#define _CRT_SECURE_NO_WARNINGS

/*

VC, GCC에서 사용

*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct __pos_t {
	int y, x;
} pos_t;

int isScope(pos_t q, int y, int x) {
	if (q.y == y) return TRUE;								// 0
	else if (q.x == x) return TRUE;							// infinite
	else if (q.y - y == q.x - x) return TRUE;				// 1
	else if (q.y - y == (-1) * (q.x - x)) return TRUE;		// -1
	else return FALSE;
}

void nQueen(pos_t queen[128], int* top, int N, int y, int* cnt) {
	int i, x, is_inline;

	if (y == N) {
		(*cnt)++;
		return;
	}

	for (x = 0; x < N; x++) {
		is_inline = TRUE;
		for (i = 0; i <= *top; i++)
			if (isScope(queen[i], y, x)) {
				is_inline = FALSE;
				break;
			}	
		if (is_inline == FALSE) continue;
		
		// push
		queen[++(*top)].y = y;
		queen[(*top)].x = x;

		nQueen(queen, top, N, y + 1, cnt);

		// pop
		(*top)--;
	}
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr<nCount; itr++)
	{
		int N, top = -1, cnt = 0;
		pos_t queen[128];
		printf("#testcase%d\n", itr + 1);

		scanf("%d", &N);
		
		nQueen(queen, &top, N, 0, &cnt);

		printf("%d\n", cnt);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}