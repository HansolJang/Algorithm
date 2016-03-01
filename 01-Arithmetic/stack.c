#include <stdio.h>

typedef struct stack
{
	int top = -1;  // top의 인덱스
	int data[3];	
};

void push(stack* st, int data) {
	if(st->top == 2) {
		printf("stack is full\n");
		return;
	}

	st->data[++st->top] = data;
	printf("%d\n", data);
}

int pop(stack* st) {
	printf("%d\n", st->data[st->top]);
	return st->data[st->top--];
}

// 스택이 비었는지 확인
// pop하기 전에 꼭 호출!
bool isEmpty(stack* st) {
	if(st->top < 0) return true;
	else return false;
}
int top(stack* st) {
	return st->data[st->top];
}

int main() {
	stack st;
	push(&st, 1);
	push(&st, 2);
	push(&st, 3);
	push(&st, 4);
	if(!isEmpty(&st)) pop(&st);
	if(!isEmpty(&st)) pop(&st);
	if(!isEmpty(&st)) pop(&st);
	if(!isEmpty(&st)) pop(&st);
	else printf("stack is empty\n");

	return 0;
}