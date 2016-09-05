//https://www.acmicpc.net/problem/1726
#include <cstdio>
#include <algorithm>
using namespace std;
#define SIZE 105
#define QSIZE 100000
int map[SIZE][SIZE];
int visited[5][SIZE][SIZE]; //스탭 수 저장
int rdir[5] = {0, 0, 0, 1, -1};
int cdir[5] = {0, 1, -1, 0, 0};
pair<int, pair<int, int> > q[QSIZE];
int main() {
    int n, m, srow, scol, sdir, erow, ecol, edir;
    int frow, fcol, fdir, nrow, ncol, ndir;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++)
            scanf("%d", &map[i][j]);
    }
    scanf("%d %d %d", &srow, &scol, &sdir);
    scanf("%d %d %d", &erow, &ecol, &edir);
    if(srow == erow && scol == ecol && sdir == edir) {
        printf("0\n");
        return 0;
    }
    int front = 1, rear = 1;
    q[front++] = make_pair(sdir, make_pair(srow, scol)); //시작점 푸시
    front %= QSIZE;
    while(!(front == rear)) {
        frow = q[rear].second.first;
        fcol = q[rear].second.second;
        fdir = q[rear++].first;
        rear %=QSIZE;
        // printf("---start (%d, %d) %d\n", frow, fcol, fdir);
        for(int i=1; i<=4; i++) {
            if(fdir < 3 && i < 3) continue;
            if(fdir > 2 && i > 2) continue;
            if(!visited[i][frow][fcol]) {
                visited[i][frow][fcol] = visited[fdir][frow][fcol] + 1;
                if(frow == erow && fcol == ecol && i == edir) {
                    printf("%d\n", visited[edir][erow][ecol]);
                    return 0;
                }
                q[front++] = make_pair(i, make_pair(frow, fcol));
                front %= QSIZE;
                // printf("change (%d, %d) %d\n", frow, fcol, i);
            }
        }
        for(int i=1;i<=3;i++) {
            nrow = frow + (rdir[fdir]) * i;
            ncol = fcol + (cdir[fdir]) * i;
            if(nrow < 1 || nrow > n || ncol < 1 || ncol > m) break;
            if(map[nrow][ncol] == 1) break;
            if(!map[nrow][ncol] && !visited[fdir][nrow][ncol]) {
                visited[fdir][nrow][ncol] = visited[fdir][frow][fcol] + 1;
                if(nrow == erow && ncol == ecol && fdir == edir) {
                    printf("%d\n", visited[edir][erow][ecol]);
                    return 0;
                }
                q[front++] = make_pair(fdir, make_pair(nrow, ncol));
                front %= QSIZE;
                // printf("go (%d, %d) %d\n", nrow, ncol, fdir);
            }
        }
    }
}