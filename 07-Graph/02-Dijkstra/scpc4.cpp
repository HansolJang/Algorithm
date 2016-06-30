//scpc2회 4번문제 대피소 : 다익스트라 (시간초과)
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define SIZE 100001
struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {
    }
};
vector<Edge> g[SIZE];
int dist[SIZE];
int check[SIZE];
bool shelter[SIZE];
int inf = 1000000000;
int main(int argc, char** argv) {
	setbuf(stdout, NULL);
	int T, test_case, n, m, k, i, j, t, s, e, w, fv, nv, td, tv;
	int ans_dist, ans_vec;
	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		ans_dist = 0;
		ans_vec = 0;
		for(i=0; i<SIZE; i++) {
			g[i].clear();
			shelter[i] = false;
		}
		scanf("%d %d %d", &n, &m, &k);
		for(i=0; i<m; i++) {
			scanf("%d %d %d", &s, &e, &w);
			g[s].push_back(Edge(e, w));
			g[e].push_back(Edge(s, w));
		}
		for(i=0; i<k; i++) {
			scanf("%d", &t);
			shelter[t] = true;
		}
		for(i=1; i<=n; i++) {
			check[i] = 0;
			dist[i] = inf;
		}
		for(int start=1; start<=n; start++) {
			if(shelter[start]) {
				dist[start] = 0;
				priority_queue<pair<int, int> > q;
				q.push(make_pair(0, start));
				while(!q.empty()) {
					pair<int, int> f = q.top();
					q.pop();
					fv = f.second;
					check[fv] = start;
					for(i=0; i<g[fv].size(); i++) {
						nv = g[fv][i].to;
						if(dist[nv] > dist[fv] + g[fv][i].cost) {
							dist[nv] = dist[fv] + g[fv][i].cost;
							check[nv] = start;
							q.push(make_pair(-dist[nv], nv));
						}
					}
				}
			}
		}
		for(i=1; i<=n; i++) {
			ans_dist += dist[i];
			ans_vec += check[i];
		}
		printf("Case #%d\n", test_case);
		printf("%d\n", ans_dist);
		printf("%d\n", ans_vec);
	}
	return 0;
}