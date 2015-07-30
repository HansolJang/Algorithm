/*

n1 + n2 > max 이면 바꿀수 없을 때 
주어진 수의 가능한 모든 순서의 갯수 출력

*/

#include <stdio.h>
#include <memory.h>

void swap(int* n1, int* n2, int max) {
	if(*n1 + *n2 > max) return;
	else {
		int temp;
		temp = *n1;
		*n1 = *n2;
		*n2 = temp;
		return;
	}
}

void check_wolf(int nwolf, int* wolf, int max, int idx, int* cnt, int (*check)[11]) {
	int i, j, k;
	int temp;
	// int cpy_wolf[10];
	bool is_same;
	// memcpy(cpy_wolf, wolf, sizeof(int)*10);

	if(idx == nwolf - 1) {
		//중복 확인
		for(j=0; j<(*cnt); j++) {
			is_same = false;
			if(check[j][0] == wolf[0]) {
				is_same = true;
				printf("is_same\n");
				for(k=1; k<nwolf; k++) {
					if(is_same) {
						if(check[j][k] == wolf[k]) {
							is_same = true;
						} else {
							is_same = false;
						}
					} else break;

				}
				if(is_same) break;
			}
			
		}

			//같은것이 없으면 추가
		if(!is_same) {
			for(j=0; j<nwolf; j++) {
				check[(*cnt)][j] = wolf[j];
				printf("%d ", wolf[j]);
			}
			(*cnt)++;
			printf("\n");
			printf("cnt : %d\n", *cnt);
		}
		return;
	}


	for(i=0; i<nwolf-1; i++) {
		printf("idx : %d, i : %d\n", idx, i);
		check_wolf(nwolf, wolf, max, idx+1, cnt, check);
		// swap
		swap(&wolf[i], &wolf[i+1], max);
		// for(j=0; j<nwolf; j++) printf("%d ", wolf[j]);
		// 	printf("\n");
		check_wolf(nwolf, wolf, max, idx+1, cnt, check);
	}

}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int nwolf;
	int wolf[10] = {};
	int check[1111][11];
	int cnt;
	int max;
	int i, j;


	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		cnt = 0;
		printf("#testcase%d\n",itr+1);

		scanf("%d", &nwolf);
		for(i=0; i<nwolf; i++){
			scanf("%d ", &wolf[i]);
		}

		scanf("%d", &max);

		// for(i=0; i<nwolf; i++) {
		// 	printf("%d ", wolf[i]);
		// }
		check_wolf(nwolf, wolf, max, 0, &cnt, check);
		printf("%d\n", cnt);

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}


/*

좁은 길

좁은 길 안에 몇 마리의 늑대들이 일렬로 있다. 
그 길은 너무 좁아서 몇몇의 늑대들은 서로 지나쳐갈 수 없다. 
정확히 말하자면, 임의의 인접한 두 늑대들의 크기의 합이 maxSizeSum 보다 작거나 같은 경우에만 두 늑대의 위치를 바꿀 수 있다. 
늑대들은 좁은 길 안에서 도망칠 수 없고 서로 인접한 늑대들만이 위치를 바꿀 수 있다. 
이러한 상황에서 늑대들을 배치할 수 있는 방법의 수는 총 몇 가지나 있겠는가 ? 
늑대들의 크기가 같더라도 그들의 번호에 따라 다른 늑대라고 가정한다.

입력 형식
첫줄에 테스트케이스의 개수 T가 주어진다. 
다음 줄부터 T개의 테스트케이스에 대하여, 
첫 줄에 늑대의 수 N ( 1 <= N <= 6 ) 와 maxSizeSum ( 1 <= maxSizeSum <=1000 ) 이 주어진다. 
다음 줄부터 N 개의 숫자로 늑대들의 크기가 주어진다.

출력 형식
답을 출력하기 전에 각 테스트케이스의 순서에 따라 “#testcase1”“#testcase2”... 을 출력한다. 
그 다음에 각 테스트케이스에 대하여, 늑대를 배치할 수 있는 모든 경우의 수를 출력한다.

예제 입력
2
3 1000
1 2 3
3 4
1 2 3


예제 출력
#testcase1
6
#testcase2
3

*/