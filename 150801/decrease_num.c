/*
https://www.acmicpc.net/problem/1038
*/
#include <stdio.h>

#define QSIZE 1111

long long int queue[QSIZE] = {};
int front, rear;

void makeDecreaseNum();
void bfs();

int main()
{
	makeDecreaseNum();
	int N;
	scanf("%d", &N);
	if(N > 1022)  //1022 : 9876543210
	{
		printf("-1\n");
	}
	else
	{
		printf("%lld\n", queue[N]);
	}
	return 0;
}

void makeDecreaseNum()
{
	front = 0;
	rear = 0;
	for(long long int i=0; i<10; i++)
	{
		queue[rear++] = i;
		rear %= QSIZE;
	}

	bfs();
}

void bfs()
{
	int digit;
	while(!(front == rear))
	{
		long long int f = queue[front++];
		// printf("%lld\n", f);
		digit = f % 10;
		front %= QSIZE;

		for(int i=0; i<digit; i++)
		{
			long long int next = f * 10 + i;
			// printf("%lld\n", next);
			queue[rear++] = next;
			rear %= QSIZE;
		}
	}
}
