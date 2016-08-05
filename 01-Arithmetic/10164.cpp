//https://www.acmicpc.net/problem/10164
#include <cstdio>
#include <cstring>
using namespace std;
int d[17][17];
int row, col, k, row1, col1, row2, col2, ans;
int main() {
	memset(d, 0, sizeof(d));
	scanf("%d %d %d", &row, &col, &k);
	d[1][1] = 1;
	for(int i=1; i<=row; i++) {
		for(int j=1; j<=col; j++)
			d[i][j] += (d[i-1][j] + d[i][j-1]);
	}
	if(k == 0)
		ans = d[row][col];
	else {
		row1 = k % col == 0 ? k / col : k / col + 1;
		col1 = k % col == 0 ? col : k % col;
		k = (row * col) - k + 1;
		row2 = k % col == 0 ? k / col : k / col + 1;
		col2 = k % col == 0 ? col : k % col;
		ans = d[row1][col1] * d[row2][col2];
	}
	printf("%d\n", ans);
	return 0;
}