/*
	https://www.acmicpc.net/problem/9663
*/
#include <stdio.h>
#include <memory.h>

int abs(int a) {
	if(a > 0) return a;
	else return -a;
}

typedef struct pos
{
	int row;
	int col;
};

#define SIZE 22

int N;  // 1~15 체스판크기
pos queen_pos[SIZE];
int ans = 0;

void solve(int order, pos* queen_pos);

int main() {

	memset(queen_pos, 0, sizeof(queen_pos));
	scanf("%d", &N);

	solve(1, queen_pos);
	printf("%d\n", ans);

	return 0;
}

void solve(int order, pos* queen_pos) {
	// printf("%d (%d, %d)\n", order, queen_pos[order-1].row, queen_pos[order-1].col);
	
	if(order == N + 1) {
		ans++;
		return;
	}

	// 가능한 좌표 찾기
	for(int col=1; col<=N; col++) {
		bool is_possible = true;
		//지금까지의 퀸의 위치와 비교
		for(int i=1; i<order; i++) {
			//세로
			if(queen_pos[i].col == col) {
				// printf("col match : %d\n", col);
				is_possible = false;
				break;
			}
			//대각선
			if(abs(queen_pos[i].row - order) == abs(queen_pos[i].col - col)) {
				// printf("match row : %d col: %d, queen row: %d col:%d\n", order, col, queen_pos[i].row, queen_pos[i].col);
				is_possible = false;
				break;
			}

		}

		if(is_possible) {
			pos p;
			p.row = order;
			p.col = col;
			queen_pos[order] = p;
			// printf("next solve order: %d\n", order + 1);
			solve(order + 1, queen_pos);
		}
	}
}