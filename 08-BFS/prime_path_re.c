/*
https://www.acmicpc.net/problem/1963
*/
#include <stdio.h>
#include <memory.h>

#define SIZE 11111
#define QSIZE 444444
#define INF 987654321
#define MIN(a,b) (a) > (b) ? (b) : (a)

typedef struct pri
{
	int val;
	int step;
};

bool prime[SIZE] = {}; //1061
bool visited[SIZE] = {};
pri queue[QSIZE];
int front, rear;
int start, end;
int minStep;
int digit[4] = {1, 10, 100, 1000};

void makePrime();
int getdigit(int digit, int num);
void bfs(int start, int end);

int main()
{
	int itr;
	int nCount;
	makePrime();
	scanf("%d", &nCount);
	for(itr=0; itr<nCount; itr++)
	{
		memset(visited, 0, sizeof(visited));
		minStep = INF;
		front = 1;
		rear = 1;
		scanf("%d %d", &start, &end);

		bfs(start, end);

		if(minStep == INF)
			printf("Impossible\n");
		else
			printf("%d\n", minStep);
	}
	return 0;
}

void bfs(int start, int end)
{
	if(start == end)
	{
		minStep = 0;
		return;
	}

	pri p;
	p.val = start;
	p.step = 0;
	queue[rear++] = p;
	visited[start] = true;
	rear %= QSIZE;

	while(!(front == rear))
	{
		pri pfront = queue[front++];
		front %= QSIZE;

		int d;
		for(int i=0; i<4; i++)
		{
			d = getdigit(digit[i], pfront.val);
			// printf("get digit %d\n", d);

			for(int j=0; j<10; j++)
			{
				if(j != 0)
				{
					d += digit[i];
				}

				if(prime[d] == true && visited[d] == false)
				{
					// printf("next %d\n", d);
					pri p;
					p.val = d;
					p.step = pfront.step + 1;
					visited[d] = true;
					queue[rear++] = p;
					rear %= QSIZE;

					if(d == end)
					{
						minStep = (MIN(minStep, p.step));
						return;
					}
				}
			}
		}
	}

}	

int getdigit(int digit, int num)
{
	int cpy;
	switch(digit)
	{
		case 1:
		cpy = num - (num % 10);
		break;
		case 10:
		cpy = num - ((num % 100) / 10) * 10;
		break;
		case 100:
		cpy = num - ((num % 1000) / 100) * 100;
		break;
		case 1000:
		cpy = num - (num / 1000) * 1000;
		break;
	}
	return cpy;
}

void makePrime()
{
	bool isPrime;
	for(int i=1000; i<10000; i++)
	{
		isPrime = true;
		for(int j=2; j<i; j++)
		{
			if(j*j > i)
			{
				break;
			}

			if(i % j == 0)
			{
				isPrime = false;
				break;
			}
		}

		if(isPrime)
			prime[i] = true;
		else
			prime[i] = false;
	}
}