#include <stdio.h>

/*
	fifo(선입선출)
	0 번째 인덱스는 빈 노드로 사용!
	front = 1, rear = 1
	push(data) : q[rear++] = data;
	pop() : front++;
	empty() : if(front == rear)
	front() : q[front]
	full : if(front == rear+1) 
		->  레어가 프론트 바로 뒤에 있으면 그 칸을 채우지 않고 빈채로 두고
			큐가 꽉찼다는 메세지 출력,
			하나 더 넣었을 경우엔(빈채로 두지않고 채웠을때) front == rear가 되므로
			빈 것인지 꽉찬것인지 확인할 수 없으므로  front의 바로 뒷칸을 비어둔다. 

	(front - rear + size) % size == 1로 해야
	front = 0이고 rear는 size-1인 꽉찬 상황도 포함할 수 있음
	but, 꽉차지 않도록 큐의 사이즈를 크게 잡아줄것! 꽉차면 원하는 답을 얻을 수 없음!

	* pop하기 이전에 empty인지 꼭 확인할 것!
*/

#define SIZE 10000 // max data 개수 : 9999

typedef struct q{
	int data[SIZE];
	int front;
	int rear;
}q;

void push(q* queue, int val) 
{
	if(queue->front - queue->rear == 1) {
		printf("queue is full\n");
		return;
	}

	queue->data[queue->rear++] = val;
	queue->rear %= SIZE;
}

void pop(q* queue)
{
	queue->front++;
	queue->front %= SIZE;
}

bool is_empty(q* queue)
{
	if(queue->front == queue->rear) 
	{
		return true;
	}
	return false;
}

int get_front(q* queue)
{
	return queue->data[queue->front];
}

/*
	큐 : 방문 순서 저장
	루트 로부터
	깊이 1인 정점 모두 탐색
	깊이 2인 정점 모두 탐색.....
*/

void bfs(int root) 
{
	visited[root] = true;

	q myqueue;
	push(&myqueue, root);

	while(!is_empty(&myqueue))
	{
		// 현재 순서 추출
		int here = front(&myqueue);
		pop(&myqueue);

		//다음에 갈 정점 찾기
		for(int next=1; next<=N; next++)
		{
			// 아직 방문하지 않았고 이이어진 간선이 있다면
			if(visited[next] == false && mygraph[here][next] == 1) 
			{
				visited[next] = true;
				push(&myqueue, next);
			}
		}
	}
}