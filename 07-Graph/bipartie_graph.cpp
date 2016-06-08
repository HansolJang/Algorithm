//https://www.acmicpc.net/problem/1707
#include <cstdio>
#include <vector>
#include <memory.h>
using namespace std;
vector<int> graph[20001];
int visited[20001];
void dfs(vector<int> *graph, int start, int set) {
    visited[start] = set;
    for(int next = 0; next < graph[start].size(); next++) {
        if(visited[graph[start][next]] == 0)
            dfs(graph, graph[start][next], 3 - set);
        if(visited[graph[start][next]] == set)
            visited[graph[start][next]] = -1;
    }
}
int main() {
    int V, E, itr, sv, ev;
    bool res;
    scanf("%d", &itr);
    while(itr--) {
        memset(visited, 0, sizeof(visited));
        for(int i=0; i<=20000; i++)
            graph[i].clear();
        scanf("%d %d", &V, &E);
        for(int i = 0; i < E; i++) {
            scanf("%d %d", &sv, &ev);
            graph[sv].push_back(ev);
            graph[ev].push_back(sv);
        }
        dfs(graph, 1, 1);
        res = true;
        for(int i = 1; i <= V; i++) {
            if(visited[i] == 0 || visited[i] == -1) {
                res = false;
                break;
            }
        }
        printf("%s\n", res ? "YES" : "NO");
    }
    return 0;
}