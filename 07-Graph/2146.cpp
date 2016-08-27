//https://www.acmicpc.net/problem/2146
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define SIZE 105
#define QSIZE 1000000
int n, front, rear, num = 1;
int map[SIZE][SIZE];
int visited[SIZE][SIZE];
int rdir[4] = {0, 0, 1, -1};
int cdir[4] = {1, -1, 0, 0};
pair<int, int> q[QSIZE];
void dfs(int row, int col) {
	int nr, nc;
	bool is_edge = false;
	for(int i=0; i<4; i++) {
		nr = row + rdir[i];
		nc = col + cdir[i];
		if(map[nr][nc] == 1 && visited[nr][nc] == -1) {
			map[nr][nc] = num; visited[nr][nc] = 0;
			dfs(nr, nc);
		}
		if(nr>0 && nr<=n && nc>0 && nc<=n && map[nr][nc] == 0)
			is_edge = true;
	}
	if(is_edge) {
		q[front++] = make_pair(row, col);
		front %= QSIZE;
	}
}
int main() {
	scanf("%d", &n);
	memset(visited, -1, sizeof(visited));
	front = 1; rear = 1;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++)
			scanf("%d", &map[i][j]);
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(map[i][j] == 1) {
				map[i][j] = ++num;
				visited[i][j] = 0;
				dfs(i, j); //area labeling
			}
		}
	}
	int frow, fcol, nrow, ncol, ans = 0;
	while(!(front == rear)) {
		frow = q[rear].first;
		fcol = q[rear++].second;
		rear %= QSIZE;
		for(int i=0; i<4; i++) {
			nrow = frow + rdir[i];
			ncol = fcol + cdir[i];
			if(nrow>0 && nrow <=n && ncol>0 &&ncol<=n) {
				//visited = step, map = area number
				//when arrived
				if(visited[nrow][ncol] > 0 && map[nrow][ncol] != map[frow][fcol]) {
					ans = visited[frow][fcol] + visited[nrow][ncol];
				}
				//keep go
				if(!map[nrow][ncol] && visited[nrow][ncol] == -1) {
					visited[nrow][ncol] = visited[frow][fcol] + 1;
					map[nrow][ncol] = map[frow][fcol];
					q[front++] = make_pair(nrow, ncol);
					front %= QSIZE;
				}
			}
			if(ans) break;
		}
		if(ans) break;
	}
	printf("%d\n", ans);
	return 0;
}