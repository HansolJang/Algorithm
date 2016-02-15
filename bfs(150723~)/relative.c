//https://www.acmicpc.net/problem/2644
#include <stdio.h>

#define SIZE		111
#define QSIZE		1111
#define TRUE		1
#define FALSE		0

typedef int BOOL;
typedef struct _man {
	int num;
	int step;
} man;

int n, m;
int from_man, to_man;
int ans = -1;
BOOL map[SIZE][SIZE] = {FALSE};
BOOL visited[SIZE] = {FALSE};
man queue[QSIZE];

void bfs(int num);

int main() {
	int x, y;
	scanf("%d", &n);
	scanf("%d %d", &from_man, &to_man);
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		map[x][y] = TRUE;
		map[y][x] = TRUE;
	}
	bfs(from_man);
	printf("%d\n", ans);
	return 0;
}

void bfs(int num) {
	int front = 1;
	int rear = 1;
	man m;
	m.num = num;
	m.step = 0;
	queue[rear++] = m;
	rear %= QSIZE;

	while(!(front == rear)) {
		man fm = queue[front++];
		front %= QSIZE;
		visited[fm.num] = TRUE;
		if(fm.num == to_man) {
			ans = fm.step;
			break;
		}
		for(int i = 0; i <= n; i++) {
			if(map[fm.num][i] == TRUE && visited[i] == FALSE) {
				man nm;
				nm.num = i;
				nm.step = fm.step + 1;
				queue[rear++] = nm;
				rear %= QSIZE;
			}
		}
	}
}