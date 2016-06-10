#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int> > a[10001];
int dist[10001];
bool check[10001];
int inf = 987654321;
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int start;
    scanf("%d",&start);
    for (int i=0; i<m; i++) {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        a[x].push_back(make_pair(y, z));
    }
    for (int i=1; i<=n; i++) {
        dist[i] = inf;
    }
    dist[start] = 0;
    priority_queue<pair<int,int> > q;
    q.push(make_pair(0, start));
    while (!q.empty()) {
        pair<int, int> p = q.top();
        q.pop();
        int x = p.second;
        check[x] = true;
        for (int i=0; i<a[x].size(); i++) {
            int y = a[x][i].first;
            if (check[y] == false && dist[y] > dist[x] + a[x][i].second) {
                dist[y] = dist[x] + a[x][i].second;
                q.push(make_pair(-dist[y], y));
            }
        }
    }
    printf("%d\n", dist[n]);
    return 0;
}