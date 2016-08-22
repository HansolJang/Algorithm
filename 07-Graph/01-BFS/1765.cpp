//https://www.acmicpc.net/problem/1765
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define SIZE 1001
#define QSIZE 1000000
int n, m;
bool teammap[SIZE][SIZE];
vector<int> enemy[SIZE];
bool visited[SIZE];
int visit_cnt = 0, front = 1, rear = 1;
int q[QSIZE]; //first = person, second = 팀의 수 
void visit(int person) {
    visited[person] = true;
    visit_cnt += 1;
}
int main() {
    int v1, v2, tmp, len, ans = 0; char rel[2];
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%s %d %d", &rel[0], &v1, &v2);
        if(rel[0] == 'F') {
        	teammap[v1][v2] = true;
        	teammap[v2][v1] = true;
        } else {
            enemy[v1].push_back(v2);
            enemy[v2].push_back(v1);
        }
    }
    for(int i=1; i<=n; i++) {
    	len = enemy[i].size();
    	if(len <= 1) continue;
    	for(int j=0; j<len; j++) {
    		for(int k = j + 1; k<len; k++) {
    			teammap[enemy[i][j]][enemy[i][k]] = true;
    			teammap[enemy[i][k]][enemy[i][j]] = true;
    		}
    	}
    }
    while(n != visit_cnt) {  //모든 사람 다 볼때까지 
        for(int i=1; i<=n; i++) {
            if(!visited[i]) {
                front = 1, rear = 1;
                q[front++] = i; //시작
                front %= QSIZE;
                visit(i);
                while(!(front == rear)) {
                    int f = q[rear++];
                    rear %= QSIZE;
                    for(int j=1; j<=n; j++) {
                        if(teammap[f][j] && !visited[j]) {
                            q[front++] = j;
                            front %= QSIZE;
                            visit(j);
                        }
                    }
                }
                ans += 1;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}