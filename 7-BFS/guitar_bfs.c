/*
https://www.acmicpc.net/problem/1495
*/
#include <stdio.h>
#include <memory.h>

#define MAX(a,b) (a) > (b) ? (a) : (b)
#define INF 987654321
#define SIZE 111
#define QSIZE 111111

typedef struct sng
{
	int order;
	int vol;
}sng;

int N, S, M;
int vol[SIZE] = {};
int maxV = -INF;
sng queue[QSIZE];
bool visited[SIZE][1111] = {};
int front, rear;

void bfs(int s);

int main()
{
	front = 1;
	rear = 1;
	scanf("%d %d %d", &N, &S, &M);
	for(int i=1; i<=N; i++)
	{
		scanf("%d", &vol[i]);
	}

	bfs(S);

	if(maxV == -INF)
		printf("-1\n");
	else
		printf("%d\n", maxV);	
	return 0;
}

//해당 곡의 순서에 대한 볼륨의 가짓수 완전탐색
void bfs(int s)
{
	sng song;
	song.order = 0;
	song.vol = s;
	visited[song.order][song.vol] = true;
	queue[rear++] = song;
	rear %= QSIZE;

	while(!(front == rear))
	{
		sng sfront = queue[front++];
		front %= QSIZE;
		if(sfront.order > N)
			return;

		if(sfront.vol + vol[sfront.order + 1] <= M && visited[sfront.order + 1][sfront.vol + vol[sfront.order + 1]] == false)
		{
			sng sng;
			sng.order = sfront.order + 1;
			sng.vol = sfront.vol + vol[sfront.order + 1];
			queue[rear++] = sng;
			rear %= QSIZE;	
			visited[sng.order][sng.vol] = true;
			// printf("next order : %d vol : % d\n", sng.order, sng.vol);
			if(sng.order == N)
			{
				// printf("%d\n", sng.order);
				maxV = (MAX(maxV, sng.vol));
				if(maxV == M)
					return;
			}
		}

		if(sfront.vol - vol[sfront.order + 1] >= 0 && visited[sfront.order + 1][sfront.vol - vol[sfront.order + 1]] == false)
		{
			sng sng;
			sng.order = sfront.order + 1;
			sng.vol = sfront.vol - vol[sfront.order + 1];
			queue[rear++] = sng;
			rear %= QSIZE;	
			visited[sng.order][sng.vol] = true;
			// printf("next order : %d vol : % d\n", sng.order, sng.vol);
			if(sng.order == N)
			{
				// printf("%d\n", sng.order);
				maxV = (MAX(maxV, sng.vol));
				if(maxV == M)
					return;
			}
		}
	}

}


/*
100 20 1000
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/