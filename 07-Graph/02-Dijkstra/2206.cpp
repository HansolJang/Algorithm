//https://www.acmicpc.net/problem/2206
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int inf = 1000000000;
bool map[1001][1001];
int n, m;
int dist[2][1002][1002];
int rdir[4] = {0, 0, 1, -1};
int cdir[4] = {1, -1, 0, 0};
struct Step {
	int dist;
	int row;
	int col;
	bool is_wrap;
	bool operator > (const Step& c) const { return dist > c.dist; } 
	Step(int dist, int row, int col, bool is_wrap) : dist(dist), row(row), col(col), is_wrap(is_wrap) {
	}
};
int main() {
	scanf("%d %d", &n, &m);
	int tmp;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			scanf("%1d", &tmp);
			map[i][j] = (tmp == 0 ? false : true);
		}
	}
	dist[0][1][1] = 1;
	priority_queue<Step, vector<Step>, greater<Step> > q;
	q.push(Step(dist[0][1][1], 1, 1, false));
	while(!q.empty()) {
		Step front = q.top();
		if(front.row == n && front.col == m) {
			printf("%d\n", front.dist);
			return 0;
		}
		q.pop();
		for(int i=0; i<4; i++) {
			int nrow = front.row + rdir[i];
			int ncol = front.col + cdir[i];
			if(nrow > 0 && nrow <= n && ncol > 0 && ncol <=m) {
				//go
				if(map[nrow][ncol] == false && (dist[front.is_wrap][nrow][ncol] == 0
					|| dist[front.is_wrap][nrow][ncol] > front.dist + 1)) {
					dist[front.is_wrap][nrow][ncol] = front.dist + 1;
					q.push(Step(front.dist + 1, nrow, ncol, front.is_wrap));
				}
				//break wall if possible
				else if(map[nrow][ncol] == true && front.is_wrap == false 
					&& (dist[true][nrow][ncol] == 0 || dist[true][nrow][ncol] > front.dist + 1)) {
					dist[true][nrow][ncol] = front.dist + 1;
					q.push(Step(front.dist + 1, nrow, ncol, true));
				}
			}
		}
	}
	printf("-1\n");
	return 0;
}