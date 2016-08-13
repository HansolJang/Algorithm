//https://www.acmicpc.net/problem/5014
#include <cstdio>
#include <string>
using namespace std;
#define QSIZE 1000000
int visited[1000001] = {0, };
int q[QSIZE];
int f, s, g, u, d, front, rear, ffloor, nfloor;
int main() {
    front = 1; rear = 1;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
    q[front++] = s;
    front %= QSIZE;
    while(!(front == rear)) {
        ffloor = q[rear++];
        rear %= QSIZE;
        if(ffloor == g) {
            printf("%d\n", visited[g]);
            return 0;
        }
        nfloor = ffloor + u;
        if(u > 0 && nfloor <= f && !visited[nfloor]) {
            visited[nfloor] = visited[ffloor] + 1;
            q[front++] = nfloor;
            front %= QSIZE;
        }
        nfloor = ffloor - d;
        if(d > 0 && nfloor > 0 && !visited[nfloor]) {
            visited[nfloor] = visited[ffloor] + 1;
            q[front++] = nfloor;
            front %= QSIZE;
        }
    }
    printf("use the stairs\n");
    return 0;
}