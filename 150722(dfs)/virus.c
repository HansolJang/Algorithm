#include <stdio.h>

int n; //정점의 개수
int com[111][111];
bool visited[111];
int cnt;

void dfs(int s);

int main() {

	for(int i=0; i<111; i++) {
		for(int j=0; j<111; j++) {
			com[i][j] = 0;
		}
		visited[i] = false;
	}
	cnt = 0;

	int en; //간선의 개수
	scanf("%d", &n);
	scanf("%d", &en);

	int a, b;
	for(int i=0; i<en; i++) {
		scanf("%d %d", &a, &b);
		com[a][b] = 1;
		com[b][a] = 1;
	}

	dfs(1);
	printf("%d\n", cnt-1);

	return 0;
}

void dfs(int s) {
	cnt++;
	visited[s] = true;

	for(int next=1; next<=n; next++) {
		if(com[s][next] == 1 && visited[next] == false) {
			dfs(next);
		}
	}
}