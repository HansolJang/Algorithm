//https://www.acmicpc.net/problem/2606
#include <stdio.h>

#define SIZE 111
#define QSIZE 1111

int map[SIZE][SIZE] = {0, };
int visited[SIZE] = {0, };
int queue[QSIZE];
int nv, ne, sv, ev, i;  //number vertex, number edge, start vertex, end vertex
int cnt = 0;
void bfs(int start);

int main() {
	scanf("%d", &nv);
	scanf("%d", &ne);
	for(i = 0; i < ne; i++) {
		scanf("%d %d", &sv, &ev);
		map[sv][ev] = 1;
		map[ev][sv] = 1;
	}
	bfs(1);
	printf("%d\n", cnt);
	return 0;
}

void bfs(int start) {
	int fv;
	int front = 1;
	int rear = 1;
	visited[start] = 1;
	queue[rear++] = start;
	rear %= QSIZE;
	while(!(front == rear)) {
		fv = queue[front++];
		front %= QSIZE;
		for(i = 1; i <= nv; i++) {
			if(map[fv][i] == 1 && visited[i] == 0) {
				visited[i] = 1;
				cnt += 1;
				queue[rear++] = i;
				rear %= QSIZE;
			}
		}
	}
}