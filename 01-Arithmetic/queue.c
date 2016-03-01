#include <stdio.h>

#define SIZE 5

typedef struct queue
{
	int front = 1;
	int rear = 1;
	int data[SIZE];
};

void q_push(queue* q, int data) {
	if((q->front) % SIZE - (q->rear) % SIZE == 1) {
		printf("queue is full\n");
	}

	printf("%d\n", data);
	q->data[q->rear] = data;
	q->rear = (q->rear + 1) % SIZE;
}

int q_pop(queue* q) {
	printf("%d\n", q->data[q->front]);
	return q->front = (q->front + 1) %SIZE;
}

bool q_isEmpty(queue* q) {
	if(q->front == q->rear) return true;
	else return false;
}

int q_front(queue* q) {
	return q->data[q->front];
}

int main() {
	queue q;
	q_push(&q, 1);
	q_push(&q, 2);
	q_push(&q, 3);
	q_push(&q, 4);
	q_push(&q, 5);
	q_pop(&q);
	q_pop(&q);
	q_pop(&q);
	q_pop(&q);
	q_pop(&q);

	return 0;
}