#include <stdio.h>

int graph[10][10];
int tree[10][10];

int main() {
	int v1, v2;

	for(int i=0; i<10; i++) {
		scanf("%d %d", &v1, &v2);

		graph[v1][v2] = graph[v2][v1] = 1;
		tree[v1][v2] = 1;
	}

	printf("---------방향성이 없는 그래프-----------\n");
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}

	printf("---------방향성이 있는 그래프----------\n");
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			printf("%d ", tree[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	return 0;
}