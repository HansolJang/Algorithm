//https://www.acmicpc.net/problem/1238
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define SIZE 1001
int inf = 1000000000;
int gox[SIZE][SIZE];
int comex[SIZE][SIZE];
int total_time[SIZE];
bool check[SIZE];
int dist[SIZE];
int n, m, x, s, e, c, ans;
void dijkstra(int (*g)[SIZE]) {
	for(int i=0; i<SIZE; i++) {
		check[i] = false;
		dist[i] = inf;
	}
	int start = x;
	priority_queue<pair<int, int> > q;
	dist[start] = 0;
	q.push(make_pair(dist[start], start));
	while(!q.empty()) {
		int front = q.top().second;
		q.pop();
		check[front] = true;
		for(int i=1; i<=n; i++) {
			if(g[front][i] > 0) {
				if(check[i] == false && dist[i] > dist[front] + g[front][i]) {
					dist[i] = dist[front] + g[front][i];
					q.push(make_pair(-dist[i], i));
				}
			}
		}
	}
}
int main() {
	memset(gox, 0, sizeof(gox));
	memset(comex, 0, sizeof(comex));
	memset(total_time, 0, sizeof(total_time));
	scanf("%d %d %d", &n, &m, &x);
	for(int i=0; i<m; i++) {
		scanf("%d %d %d", &s, &e, &c);
		gox[e][s] = c;
		comex[s][e] = c;
	}
	ans = 0;
	dijkstra(gox);
	for(int i=1; i<=n; i++)
		total_time[i] += dist[i];
	dijkstra(comex);
	for(int i=1; i<=n; i++) {
		total_time[i] += dist[i];
		ans = max(ans, total_time[i]);
	}
	printf("%d\n", ans);
}