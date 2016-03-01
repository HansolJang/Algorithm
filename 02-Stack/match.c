#include <stdio.h>

typedef struct stack
{
	int top;  // top의 인덱스
	int data[55];
};

void push(stack* st, int data) {
	if(st->top == 54) {
		printf("stack is full\n");
		return;
	}

	st->data[++st->top] = data;
	// printf("%d\n", data);
}

int pop(stack* st) {
	// printf("%d\n", st->data[st->top]);
	return st->data[st->top--];
}

int top(stack* st) {
	return st->data[st->top];
}

int get_size(stack* st) {
	return st->top;
}

int isEmpty(stack* st){
	if(st->top == -1) return 1;
	else return 0;
}

int main() {
	char input[55];
	int i;
	stack st;
	st.top = -1;
	for(i=0; i<55; i++) {
		input[i] = -1;
	}

	scanf("%s", &input);

	for(i=0; i<55; i++) {
		if(input[i] == 40) {
			// printf("open: %d\n", i);
			push(&st, i);
			// printf("%d\n",top(&st));
		}

		if(input[i] == 41) {
			// printf("close: %d\n", i);
			int popnum = top(&st);  //확인
			// printf("%d\n", popnum);
			if(popnum > 0 || popnum < 56) {
				printf("%d %d\n", pop(&st), i);
			} else {
				printf("not match\n");
			}
		}

		if(input[i] == 0) {
			if(!isEmpty(&st)) {
				printf("not match\n");
			}
			break;
		}
	}
}