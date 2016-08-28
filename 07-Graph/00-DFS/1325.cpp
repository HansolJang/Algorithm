//https://www.acmicpc.net/problem/1325
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define SIZE 10001
int n, m, v1, v2, tmp, max_cnt = 0, max_start = 0;
vector<int> map[SIZE];
bool visited[SIZE];
int ans[SIZE];
int dfs(int vec) {
    int len = map[vec].size();
    int ret = 1;
    for(int i=0; i<len; i++) {
        if(!visited[map[vec][i]]) {
            visited[map[vec][i]] = true;
            ret += dfs(map[vec][i]);
        }
    }
    return ret;
}
int main() {
    int idx = 0;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &v1, &v2);
        map[v2].push_back(v1);
    }
    for(int i=1; i<=n; i++) {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        tmp = dfs(i);
        if(max_cnt == tmp) {
            ans[idx++] = i;
        }
        else if(max_cnt < tmp) {
            max_cnt = tmp;
            idx = 0;
            ans[idx++] = i;
        }
    }
    for(int i=0; i<idx; i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}