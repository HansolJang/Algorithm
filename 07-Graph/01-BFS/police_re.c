/*

문제:http://59.23.113.171/30stair/catch_cow/catch_cow.php?pname=catch_cow

*/

#include <stdio.h>

typedef struct police{
	int val;
	int time;
}police;

police queue[11111];
int check[111111];

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int n, k;
	int i;
	int front, rear;
	int val;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		scanf("%d %d", &n, &k);
		for(i=0; i<10001; i++) {
			check[i] = 0;
		}

		front = 0;
		rear = -1;
		police p;
		p.val = n;
		p.time = 0;
		queue[++rear] = p;
		check[p.val] = 1;

		while(1){

			val = queue[front].val;

			if(val == k) {
				printf("%d\n", queue[front].time);
				break;
			} else {
				// printf("%d\n", queue[front]);
				if(val < k) {
					// n-1
					if(val > 0) {
						if(check[val - 1] == 0) {
							police p1;
							p1.val = val - 1;
							p1.time = (queue[front].time) + 1;
							queue[++rear] = p1;
							check[val] = 1;
						}
					}
					
					
					// n+1
					if(val + 1 < 111111) {
						if(check[val + 1] == 0) {
							police p2;
							p2.val = val + 1;
							p2.time = (queue[front].time) + 1;
							queue[++rear] = p2;
							check[p2.val] = 1;
						}
					}
					
					// 2*n
					if(val * 2 < 111111 && val * 2 < k) {
						if(check[val * 2] == 0) {
							police p3;
							p3.val = val * 2;
							p3.time = (queue[front].time) + 1;
							queue[++rear] = p3;
							check[p3.val] = 1;
						}
					} 
					
				} else {
					// n-1
					if(val > 0) {
						if(check[val - 1] != 1) {
							police p1;
							p1.val = val - 1;
							p1.time = (queue[front].time) + 1;
							queue[++rear] = p1;
							check[p1.val] = 1;
						}
					}
				}
				front++;
			}
		}

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}