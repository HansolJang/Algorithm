/*
	http://59.23.113.171/30stair/prime_path/prime_path.php?pname=prime_path
*/
#include <stdio.h>

#define QSIZE 444444

	typedef struct prime
	{
		int val;
		int step;
	};
prime queue[QSIZE]; //1111*4*9 (한번에 4자리 변경가능)
bool visited[11111][2] = {};  //[0] is_prime, [1] visited
int front, rear;
int step = 0;
int start, end;

int digit[4] = {0, 10, 100, 1000};

void make_prime();
void bfs(int s, int a);

int main() {
	//소수 세팅
	make_prime();
	front = 1;
	rear = 1;

	scanf("%d %d", &start, &end);

	if(start == end) {
		printf("0\n");
	} else {
		bfs(start, end);
		printf("%d\n", step);
	}

	return 0;
}

void make_prime() {
	for(int i=1000; i<10000; i++) {
		bool is_prime = true;
		for(int j=2; j<i; j++) {
			if(j*j > i) break;
			if(i % j == 0) {
				is_prime = false;
				break;
			}
		}
		if(is_prime) {
			visited[i][0] = true;
		}
	}
}

void bfs(int s, int a) {
	prime p;
	p.val = s;
	p.step = 0;
	queue[rear++] = p;
	rear %= QSIZE;

	while(!(front == rear)) {
		prime pfront = queue[front++];
		front %= QSIZE; //pop
		visited[pfront.val][1] = true;  //visit

		for(int i=0; i<4; i++) {
			int next = pfront.val;  // copy	
			if(i==0) {
				next -= next % 10;  //xxx0
			} else if(i==1) {
				next -= (next % 100 - next % 10);  //xx0x
			} else if(i==2) {
				next -= (next % 1000 - next % 100); //x0xx 
			} else {
				next -= (int)(next / 1000) * 1000;
			}
			// printf("-----setting %d\n", next);
			int cpy = next;
			for(int j=0; j<10; j++) {

				if(i==0) {
					next += j;
				} else {
					next += digit[i] * j;
				}
				// printf("%d\n", next);
				if(next >= 1000 && next <10000) {
					if(visited[next][0] == true && visited[next][1] == false) {
					visited[next][1] = true; //visit
					prime nextP;
					nextP.val = next;
					nextP.step = pfront.step + 1;
					queue[rear++] = nextP;  //enqueue
					rear %= QSIZE;
					if(next == a) {
						step = nextP.step;
						return;
					}
				}
				next = cpy;  //복원
			}
		}
	}
}
}