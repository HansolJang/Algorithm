//https://www.acmicpc.net/problem/1162
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define SIZE 10001
int inf = 1000000000;
//SIZE * SIZE 배열을 만들면 메모리 초과이기 때문에 SIZE 배열의 동적배열에 간선개수 만큼만 2차원으로
struct Edge {
	int to;
	int cost;
	Edge(int to, int cost) : to(to), cost(cost) {
	}
};
//큐의 원소가 되는 구조체: 현재의 거리, 정점, 포장회수를 저장
struct Cur {
	int d;
	int vertex;
	int wrap_cnt;
	bool operator > (const Cur& c) const { return d > c.d; } 
	Cur(int d, int vertex, int wrap_cnt) : d(d), vertex(vertex), wrap_cnt(wrap_cnt) {
	}
};
vector<Edge> city[SIZE];
bool check[SIZE];
int dist[SIZE];
int n, m, k, s, e, w, fv, flen, nv, t;
int main() {
	for(int i=0; i<SIZE; i++)
		dist[i] = inf;
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0; i<m; i++) {
		scanf("%d %d %d", &s, &e, &w);
		city[s].push_back(Edge(e, w));
		city[e].push_back(Edge(s, w));
	}
	priority_queue<Cur, vector<Cur>, greater<Cur> > q;
	//시작점 = 1(서울)
	dist[1] = 0;
	q.push(Cur(dist[1], 1, 0));
	while(!q.empty()) {
		Cur f = q.top();
		q.pop();
		fv = f.vertex;
		check[fv] = true;
		flen = city[fv].size();
		for(int i=0; i<flen; i++) {
			nv = city[fv][i].to;
			//t = 그대로 지나가는 비용
			t = f.d + city[fv][i].cost;
			if(!check[nv])
				q.push(Cur(t, nv, f.wrap_cnt));
			//포장이 가능할 경우 포장
			if(f.wrap_cnt < k) {
				if(!check[nv]) {
					q.push(Cur(f.d, nv, f.wrap_cnt + 1));
					t = min(t, f.d);
				}
			}
			//모든 경우 중 최소값을 dist 배열에 저장
			dist[nv] = min(dist[nv], t);
		}
	}
	printf("%d\n", dist[n]);
	return 0;
}