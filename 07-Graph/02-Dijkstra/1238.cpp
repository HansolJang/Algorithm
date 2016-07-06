//https://www.acmicpc.net/problem/1238
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define SIZE 1001
int inf = 1000000000;
int town[SIZE][SIZE];
int total_time[SIZE];
bool check[SIZE];
int dist[SIZE];
int n, m, x, s, e, c, start, front, next, ans;
int main() {
	memset(town, 0, sizeof(town));
	memset(total_time, 0, sizeof(total_time));
	scanf("%d %d %d", &n, &m, &x);
	for(int i=0; i<m; i++) {
		scanf("%d %d %d", &s, &e, &c);
		town[s][e] = c;
	}
	ans = 0;
	//가는 비용: 1~n 정점까지 모두 다익스트라 진행
	//돌아오는 비용: n + 1번째에 x를 시작으로 다시 다익스트라 진행
	for(int i=1; i<=n + 1; i++) {
		for(int j=0; j<SIZE; j++) {
			check[j] = false;
			dist[j] = inf;
		}
		start = (i == n + 1 ? x : i);
		priority_queue<pair<int, int> > q;
		dist[start] = 0;
		q.push(make_pair(dist[start], start));
		while(!q.empty()) {
			front = q.top().second;
			q.pop();
			check[front] = true;
			for(next=1; next<=n; next++) {
				if(town[front][next] > 0) {
					if(check[next] == false && dist[next] > dist[front] + town[front][next]) {
						dist[next] = dist[front] + town[front][next];
						q.push(make_pair(-dist[next], next));
					}
				}
			}
		}
		//가는 비용
		if(i < n + 1)
			total_time[start] += dist[x];
		//돌아오는 비용
		else {
			for(int j=1; j<=n; j++) {
				total_time[j] += dist[j];
				ans = max(ans, total_time[j]);
			}
		}
	}
	printf("%d\n", ans);
}