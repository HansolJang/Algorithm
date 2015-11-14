#include <stdio.h>
#include <stdlib.h>

int N;
int map[33][33];
int danji; //최종 단지
int dcnt[333] = {}; // 단지마다 집의 수
void dfs(int row, int col, int danji);

int compare (const void *a, const void *b)
{
    const int *ia = (const int *)a; // casting pointer types 
    const int *ib = (const int *)b;
    return *ia  - *ib; 
}

int dirR[4] = {0, 0, 1, -1};
int dirC[4] = {1, -1, 0, 0};

int main() {

	scanf("%d", &N);
	for(int i=1; i<N+1; i++) {
		for(int j=1; j<N+1; j++) {
			scanf("%d", &map[i][j]);
			if(map[i][j] == 1) {
				map[i][j] = -1;
			}
		}
	}

	//한칸씩 확인하면서 -1을 만나면 재귀호출
	danji = 1;
	for(int i=1; i<N+1; i++) {
		for(int j=1; j<N+1; j++) {
			if(map[i][j] == -1) {
				dfs(i, j, danji);
				danji++;
			}
		}
	}

	qsort(dcnt, danji+1, sizeof(int), compare);

	printf("%d\n", danji-1);
	for(int i=1; i<333; i++) {
		if(dcnt[i] != 0) {
			printf("%d\n", dcnt[i]);
		}
	}

	return 0;
}

void dfs(int row, int col, int danji) {

	map[row][col] = danji;
	dcnt[danji]++;

	for(int i=0; i<4; i++) {
		int nextR = row + dirR[i];
		int nextC = col + dirC[i];

		if(map[nextR][nextC] == -1) {
			dfs(nextR, nextC, danji);
		}
	}

}

/*
7
0 1 1 0 1 0 0 
0 1 1 0 1 0 1
1 1 1 0 1 0 1
0 0 0 0 1 1 1 
0 1 0 0 0 0 0
0 1 1 1 1 1 0
0 1 1 1 0 0 0


1 0 1 0 0 0 0 0 0 1 1 0 0 0 0 1 0 1 1 0
1 0 1 0 0 0 1 1 1 1 1 1 0 0 0 0 1 0 0 1
0 0 1 0 1 0 1 1 0 1 1 0 0 0 1 0 1 1 0 1
0 0 1 1 1 1 0 1 1 1 0 1 1 0 1 1 0 1 1 0
1 0 0 0 1 1 1 1 1 0 0 0 0 1 1 1 1 1 0 0
1 1 0 1 1 1 0 0 1 1 0 0 1 0 1 0 1 1 1 1
0 1 0 1 1 1 0 1 0 0 1 0 0 1 0 1 1 1 1 0
1 1 1 1 0 0 1 0 0 1 0 1 0 0 1 0 0 1 0 1
0 0 1 0 0 0 1 0 0 0 0 1 1 1 0 0 1 1 1 0
1 0 0 1 0 0 0 1 0 0 1 0 0 0 1 0 0 0 1 0
0 1 0 1 0 0 0 0 1 1 1 1 0 0 0 0 0 1 1 1
1 1 0 1 0 1 0 0 0 0 1 0 0 0 1 0 1 0 1 1
0 1 1 0 1 1 0 0 0 1 1 1 0 1 1 0 0 1 0 0
0 1 1 0 1 0 1 0 0 0 1 0 0 0 1 1 0 1 1 1
0 1 0 0 1 1 0 1 1 1 1 1 0 1 0 0 0 0 0 0
1 0 1 1 1 0 0 1 1 1 0 0 1 0 0 0 0 1 0 0
1 0 1 0 0 1 1 0 0 0 1 1 0 0 0 0 0 1 0 1
1 0 0 0 0 1 1 1 0 1 1 1 0 1 0 0 0 0 1 0
0 1 0 0 1 0 0 1 0 0 0 1 0 0 1 1 0 1 0 1
1 1 0 1 0 0 0 1 1 1 0 1 1 1 0 1 0 1 1 1

*/