/*

VC, GCC에서 사용

*/

/*
	소수의길 
	소수를 먼저 다 구해놓고
	현재의 수에서 한자리씩 바꿔보면서 그 수가 소수면 방문->enqueue
	바꿔야할 소수가 되면 time 출력
	1033->8179 = 6
*/

#include <stdio.h>

typedef struct prime{
	int val;
	int time;
}prime;

void visit_prime(prime* queue, int* visit, int num, int time, int* rear) {
	visit[num] = 1;
	prime p;
	p.val = num;
	p.time = time;
	queue[++(*rear)] = p;
	// printf("visit prime : %d, time : %d, rear : %d\n", num, time, *rear);
	return;
}

int prime_arr[11111]; //1061개 1000~9999
prime queue[1111];
int visit[11111]; //1000~9999

int main() {

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	bool is_prime;
	int front, rear;
	int before, after;
	int i, j;
	int chg_prime;
	int cpy_prime;

	// 1000~9999 사이의 소수 초기 세팅
	for(i = 1000; i<10000; i++) {
		is_prime = true;
		for(int k=2; k<i; k++) {
			if(i % k == 0) {
				is_prime = false;
			}
			if(k*k > i) break;  //root값까지만 
		}
		if(is_prime) {
			prime_arr[i] = 1;
		}
		else prime_arr[i] = 0;
	}

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		scanf("%d %d", &before, &after);

		for(i=1000; i<10000; i++) {
			visit[i] = 0;
		}

		front = 0;
		rear = -1;
		prime p;
		p.val = before;
		p.time = 0;
		visit[p.val] = 1;
		queue[++rear] = p;

		while(1) {
			// printf("-------------front : %d, queue[front] : %d\n", front, queue[front].val	);
			if(queue[front].val == after) {
				printf("%d\n", queue[front].time);
				break;
			}

			for(i=0; i<4; i++) {

				if(i == 0) {
					//xxx0
					chg_prime = ((int)queue[front].val/10) * 10;
				} else if(i == 1) {
					//xx0x
					chg_prime = ((int)queue[front].val/100) * 100 + queue[front].val%10;
				} else if (i == 2) {
					//x0xx
					chg_prime = ((int)queue[front].val/1000) * 1000 + queue[front].val%100;
				} else {
					//xxx
					chg_prime = queue[front].val - ((int)queue[front].val/1000) * 1000;					
				}
				//한번 더한 후 복원할 복사값
				cpy_prime = chg_prime;
				// printf("chg prime : %d\n", chg_prime);

				//각 자릿수마다 0~9까지 더한 후 소수이면 방문
				for(int j=0; j<10; j++) {

					chg_prime = cpy_prime;

					if(i == 0) {
						chg_prime += j;
					} else if(i == 1) {
						chg_prime += j*10;
					} else if(i == 2) {
						chg_prime += j*100;
					} else {
						if(j != 0) {
							chg_prime += j*1000;
						}
					}

					if(chg_prime != queue[front].val) {
						if(prime_arr[chg_prime] == 1) {
							if(visit[chg_prime] == 0) {
								visit_prime(queue, visit, chg_prime, queue[front].time+1, &rear);
							}
						}
					}
				} // for: 각자리 0~9
			} // for: 1, 10, 100, 1000

			front++;

		} //while
		
	} //testcase

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}