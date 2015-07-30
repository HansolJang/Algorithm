/*

VC, GCC에서 사용

*/

#include <stdio.h>

typedef struct stack {
	int top;
	int data[1000];
}stack;

void push(stack* st, int data) {
	if(st->top == 999) {
		return;
	}
	st->data[++st->top] = data;
	return;
}

int pop(stack* st) {
	return st->data[st->top--];
}

int top(stack* st) {
	return st->data[st->top];
}

bool is_empty(stack* st) {
	if(st->top < 0) return true;
	else return false;
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int num;
	int input[1111];
	int popnum;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		scanf("%d", &num);

		stack st;
		st.top = -1;
		popnum = 1;

		for(int i=0; i<num; i++) {
			scanf("%d", &input[i]);
			push(&st, input[i]);
			while(1) {
				if(top(&st) == popnum) {
					pop(&st);
					popnum++;
				} else break;
			}
		}

		if(is_empty(&st)) printf("Yes\n");
		else printf("No\n");
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}