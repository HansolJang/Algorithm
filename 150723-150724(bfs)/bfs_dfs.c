/*
	https://www.acmicpc.net/problem/1260
*/
#include <stdio.h>

#define SIZE 1111
#define QSIZE 1111111

int mygraph[SIZE][SIZE] = {};
int N, M, V;  //정점수, 간선수, 시작위치
bool d_visited[SIZE] = {};
bool b_visited[SIZE] = {};
int queue[QSIZE];
int front, rear;

void dfs(int s);
void bfs(int root);

int main() {

	scanf("%d %d %d", &N, &M, &V);
	int a, b;
	for(int i=0; i<M; i++) {
		scanf("%d %d", &a, &b);
		mygraph[a][b] = 1;
		mygraph[b][a] = 1;
	}
	front = 1;
	rear = 1;

	dfs(V);
	printf("\n");
	bfs(V);
	printf("\n");

	return 0;
}

void dfs(int s) {
	printf("%d ", s);
	d_visited[s] = true;

	for(int i=1; i<=N; i++) {
		if(mygraph[s][i] == 1 && d_visited[i] == false) {
			dfs(i);
		}
	}
}

void bfs(int s) {
	b_visited[s] = true;
	queue[rear++] = s;
	rear %= QSIZE;

	while(!(front == rear)) {
		int fpos = queue[front++];
		printf("%d ", fpos);
		front %= QSIZE;

		for(int i=1; i<=N; i++) {
			if(mygraph[fpos][i] == 1 && b_visited[i] == false) {
				queue[rear++] = i;
				rear %= QSIZE;
				b_visited[i] = true;
			}
		}
	}
}