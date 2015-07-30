/*

VC, GCC에서 사용

*/

#include <stdio.h>

int next_com(int com[][111], int* visit, int num, int cnum) {
	for(int k=0; k<cnum; k++) {
		// printf("num : %d, k ; %d, com[num][k]:%d\n", num, k, com[num][k]);
		if(com[num][k] == 1 && visit[k] == 0) return k;
	}
	return -1;
}

int com[111][111];
int visit[111];
int queue[111];

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int front, rear;
	int cnum;
	int ednum;
	int ed_begin, ed_end;
	int i, j;
	int next;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		for(i=0; i<111; i++) {
			for(j=0; j<111; j++) {
				com[i][j] = 0;
			}
			visit[i] = 0;
		}

		printf("#testcase%d\n",itr+1);
		scanf("%d", &cnum);
		scanf("%d", &ednum);

		for(i=0; i<ednum; i++) {
			scanf("%d %d", &ed_begin, &ed_end);
			com[ed_begin][ed_end] = 1;
			com[ed_end][ed_begin] = 1;
		}

		// for(i=0; i<cnum; i++) {
		// 	for(j=0; j<cnum; j++) {
		// 		printf("%d ", com[i][j]);
		// 	}
		// 	printf("\n");
		// }

		front = 0;
		rear = 0;
		queue[front] = 1;
		visit[1] = 1;
		while(!(front > rear)) {
			// printf("while : %d\n", queue[front]);
			next = next_com(com, visit, queue[front], cnum);
			// printf("next : %d\n", next);
			while(next != -1) {
				visit[next] = 1;
				queue[++rear] = next;
				next = next_com(com, visit, queue[front], cnum);
				// printf("next : %d\n", next);
			}
			front++;
		}
		
		j=0;
		for(i=0; i<cnum; i++) {
			if(visit[i] == 1) {
				// printf("visit : %d\n", i);
				j++;
			}
		}

		printf("%d\n", j-1);  //1을 뺌
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}