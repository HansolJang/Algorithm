#include <stdio.h>
#include <memory.h>

#define SIZE 1111111

int N;
int max_jump;
int front, rear;
int ans;
int stone[SIZE]; //col0: position, col1: min_step

int solve(int N, int max_jump);

int main(void) {

	setbuf(stdout, NULL);

	int T;
	int test_case;
	

	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		//reset
		memset(stone, 0, sizeof(stone));

		//input
		scanf("%d", &N);
		for(int i=1; i<=N; i++)
		{
			scanf("%d", &stone[i]);
			// printf("stone[%d] : %d\n", i, stone[i]);
		}
		scanf("%d", &max_jump);

		printf("Case #%d\n", test_case);
		printf("%d\n", solve(N, max_jump));

	}

	return 0;
}

int solve(int N, int max_jump)
{
	ans = 0;
	int cur = 0;
	while(cur <= N)
	{
		if(cur == N)
			return ans;

		for(int i=1;; i++)
		{
			if(stone[cur+i] - stone[cur] > max_jump
				|| stone[cur + i] == 0)
			{
				if(i != 1)
				{
					cur += (i-1);
					ans++;
					// printf("possible : %d\n", cur);
					break;
				}
				else
				{
					if(stone[cur + i] == 0)
						break;
					else
						return -1;
				}
			}
		}
	}
}