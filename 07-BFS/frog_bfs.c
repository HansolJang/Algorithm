#include <stdio.h>
#include <memory.h>

#define SIZE 1111111
#define INF 987654321

typedef struct frog {
	int pos;
	int step;
}frog;

int N;
int max_jump;
int front, rear;
int ans;
int stone[SIZE][2]; //col0: position, col1: min_step
frog queue[SIZE];

int bfs();

int main(void) {

	setbuf(stdout, NULL);

	int T;
	int test_case;
	

	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		//reset
		for(int i=0; i<SIZE; i++)
		{
			stone[i][0] = 0;
			stone[i][1] = INF;
		}
		ans = INF;
		stone[0][0] = 0;

		//input
		scanf("%d", &N);
		for(int i=1; i<=N; i++)
		{
			scanf("%d", &stone[i][0]);
			// printf("stone[%d] : %d\n", i, stone[i]);
		}
		scanf("%d", &max_jump);

		printf("Case #%d\n", test_case);
		printf("%d\n", bfs());

	}

	return 0;
}

int bfs()
{
	bool cannot_jump;
	front = 1;
	rear = 1;

	frog f;
	f.pos = 0;
	f.step = 0;
	queue[rear++] = f;
	rear %= SIZE;

	while(front <= rear)
	{
		//pop
		frog t_frog = queue[front++];
		front %= SIZE;
		// printf("[pop] pos : %d, value: %d, step : %d \n", t_frog.pos, stone[t_frog.pos][0], t_frog.step);

		for(int i=t_frog.pos + 1;; i++)
		{
			//next step
			if(stone[i][0] > 0 &&
				stone[i][0] <= stone[t_frog.pos][0] + max_jump
				&& stone[i][1] > t_frog.step + 1)
			{
				frog f;
				f.pos = i;
				f.step = t_frog.step + 1;
				queue[rear++] = f;
				rear %= SIZE;
				stone[i][1] = f.step;
				// printf("next : %d, step: %d\n", f.pos, f.step);

				//arrive
				if(i == N)
					return f.step;
			}
			else if(stone[i][0] > stone[t_frog.pos][0] + max_jump)
				break;
		}
	}

	return -1;
}