#include <stdio.h>

int mygraph[22][22];
bool visited[22];
int n, start;
	
void dfs(int s);

int main() {
	scanf("%d %d", &n, &start);
	for(int i=0; i<=n; i++) {
		visited[i] = false;
	}

	int a, b;
	while(scanf("%d %d", &a, &b) != EOF) {
		mygraph[a][b] = 1;
		mygraph[b][a] = 1;
	}

	dfs(start);
}

void dfs(int s) {
	printf("%d ", s);
	visited[s] = true;

	for(int next=0; next<=n; next++) {
		if(mygraph[s][next] == 1 && visited[next] == false) {
			dfs(next);
		}
	}
}