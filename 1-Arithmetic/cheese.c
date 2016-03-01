//https://www.acmicpc.net/problem/2636
#include <stdio.h>
#include <memory.h>

#define SIZE 111

int row,col;
int i, j;
int map[SIZE][SIZE] = {0, };
int mapcpy[SIZE][SIZE] = {0, };
int rowdir[4] = {0, 0, 1, -1};
int coldir[4] = {1, -1, 0, 0};
int checkair(int row, int col);

int main() {
	scanf("%d %d", &row, &col);
	for(i = 1; i <= row; i++) {
		for(j = 1; j <= col; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int isNoCheese = 0;
	int hour = 0;
	int cheesecnt = 0;
	// while(!isNoCheese) {
		isNoCheese = 1;
		printf("%d %d\n", row, col);
		for(i = 1; i <= row; i++) {
			for(j = 1; j <= col; j++) {
				if(map[i][j] == 1) {
					isNoCheese = 0;
					if(checkair(i, j) >= 2) {
						mapcpy[i][j] = 0;
					}
				}
				printf("%d ", mapcpy[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		memcpy(map, mapcpy, sizeof(map));
		hour += 1;
	// }
	for(i = 1; i <= row; i++) {
			for(j = 1; j <= col; j++) {
				if(mapcpy[i][j] == 1) {
					cheesecnt += 1;
				}
			}
		}
	printf("%d\n", hour);
	printf("%d\n", cheesecnt);
	return 0;
}

int checkair(int row, int col) {
	int nrow, ncol;
	int aircnt = 0;
	for(i = 0; i < 4; i++) {
		nrow = row + rowdir[i];
		ncol = col + coldir[i];
		if(map[nrow][ncol] == 0)
			aircnt += 1;
	}
	return aircnt;
}