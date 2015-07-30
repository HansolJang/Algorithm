#include <stdio.h>
#include <stdlib.h>

/*
	최장 거리는 가장 벽에있는 것에서 반대쪽 벽까지의 거리
	최단 거리는 가장 가운데에 있는 것에서 가까운쪽의 벽의 거리
*/

int main() {
	int size;
	int num;
	int *ant;
	int min; // 가장 벽 가까이 있는 수 
	int max = 0; // 가장 가운데 수 
	int half;
	scanf("%d %d\n", &size, &num);
	half = (int)size/2;
	ant = (int *)malloc(sizeof(int) * num);
	for(int i=0; i<num; i++) {
		scanf("%d ", &ant[i]);
	}

	for(int i=0; i<num; i++) {
		int dis;  // 벽에서의 거리
		int v = (int)ant[i]/half; //몫
		int r = ant[i] % half; //나머지
		
		if(v > 0) {
			//오른쪽 
			dis = half - r;
		} else {
			//왼쪽
			dis = r;
		}
		// printf("%d\n", dis);
		//가장 작은 수
		//벽에서의 거리가 작으면 작을수록
		if(dis < min) {
			min = dis;
		}

		//가장 중간 수
		if(i == 0) {
			max = dis;
		} else {
			if(dis > max) {
				max = dis;
			}
		}
	}

	printf("%d %d", max, size-min);

	free(ant);
	return 0;
}