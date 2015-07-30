/*
	https://www.acmicpc.net/problem/1697
*/
#include <stdio.h>

#define QSIZE 333333

	typedef struct runner
	{
		int pos;
		int time;
	};

	runner queue[QSIZE];
	bool visited[QSIZE];
int N, K; // N:상욱 K:동주 -> N를 움직여 K이 되면 시간 출력
int front, rear;

void bfs(int N, int K);

int main() {

	front = 1;
	rear = 1;
	for(int i=0; i<QSIZE; i++) {
		visited[i] = false;
	}
	scanf("%d %d", &N, &K);

	if(N == K) {
		printf("0\n");
	} else if(N > K) {
		printf("%d\n", N-K);
	} else {
		bfs(N, K);
	}

	return 0;
}

void bfs(int N, int K) {
	runner r;
	r.pos = N;
	r.time = 0;
	queue[rear++] = r;
	rear %= QSIZE;

	while(!(front == rear)) {
		runner rfront = queue[front++];
		front %= QSIZE;  //pop
		visited[rfront.pos] = true;  //방문
		// printf("pos : %d time : %d\n", rfront.pos, rfront.time);
		runner nextR;
		// -1
		if(rfront.pos-1 >= 0 && rfront.pos-1 <= 100000 && visited[rfront.pos-1] == false) {
			nextR.pos = rfront.pos - 1;
			nextR.time = rfront.time + 1;
			queue[rear++] = nextR;
			rear %= QSIZE;
			visited[nextR.pos] = true;
			if(nextR.pos == K) {
				printf("%d\n", nextR.time);
				return;
			}
		}

		//클때만 더하고 곱함
		if(rfront.pos < K) {
			// +1
			if(rfront.pos+1 <= 100000 && rfront.pos+1 >= 0 && visited[rfront.pos+1] == false) {
				nextR.pos = rfront.pos + 1;
				nextR.time = rfront.time + 1;
				queue[rear++] = nextR;
				rear %= QSIZE;
				visited[nextR.pos] = true;
				if(nextR.pos == K) {
					printf("%d\n", nextR.time);
					return;
				}
			}

			// *2
			if(rfront.pos*2 <= 100000 && rfront.pos*2 >= 0 && visited[rfront.pos*2] == false) {
				nextR.pos = rfront.pos * 2;
				nextR.time = rfront.time + 1;
				queue[rear++] = nextR;
				rear %= QSIZE;
				visited[nextR.pos] = true;
				if(nextR.pos == K) {
					printf("%d\n", nextR.time);
					return;
				}
			}
		}	
	}
}