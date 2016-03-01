#include <stdio.h>

int main(){

	int itr = 0;
	int i, j;

	while(1) {
		itr++;
		printf("#testCase%d\n", itr);
		int edge_start, edge_end;
		int node_start[111];
		int node_end[111];
		int isTree = 1;
		for(i=0; i<111; i++) {
			node_start[i] = 0;
			node_end[i] = 0;
		}

		while(1) {
			scanf("%d %d", &edge_start, &edge_end);
	
			if(edge_start == -1 && edge_end == -1) {
				return 0;
			} else if(edge_start == 0 && edge_end == 0) {

				int root_cnt = 0;
				int cnt = 0;

				for(i=0; i<111; i++) {
					if(node_end[i] == 0) {
						if(node_start[i] > 0) {
							root_cnt++;
						} else if(node_start[i] == 0) {
							cnt++;
						}
					} else if(node_end[i] > 1) {
						isTree = 0;
					}
					
					// printf("start[%d] : %d, end[%d] : %d\n", i, node_start[i], i, node_end[i]);
				}
				// printf("%d\n", root_cnt);
				if(root_cnt == 1 || cnt == 111) {
					if(isTree == 1)	isTree = 1;  //바뀐적이 없을때만
				} else {
					isTree = 0;
				}

				if(isTree) {
					printf("Case %d is a tree.\n", itr);
				} else {
					printf("Case %d is not a tree.\n", itr);
				}
				break;

			} else {
				node_end[edge_end]++;
				node_start[edge_start]++;
			}
		}
	}
}