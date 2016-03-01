#include <stdio.h>

typedef struct stack{
	int top;
	int data[55];
}stack;

void push(stack* st, int data) {
	if(st->top == 54) return;
	st->data[++st->top] = data;
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
	char input[55];
	int res[111];
	int i;
	int res_cnt;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		bool is_match = true;
		res_cnt = 0;
		printf("#testcase%d\n",itr+1);
		for(i=0; i<111; i++) {
			res[i] = -1;
			if(i < 55) {
				input[i] = -1;
			}
		}
		scanf("%s", &input);
		stack st;
		st.top = -1;

		for(i=0; i<55; i++) {
			if(input[i] == -1) break;
			else {
				if(input[i] == '(') {
					push(&st, i);
				} else if(input[i] == ')') {
					if(!is_empty(&st)) {
						res[res_cnt] = pop(&st);
						res[res_cnt+1] = i;
						res_cnt += 2;
					} else {
						is_match = false;
						break;
					}
				}
			}
		}

		// while(!is_empty(&st)) {
		// 	printf("not match\n");
		// 	pop(&st);
		// }
		if(!is_empty(&st)) is_match = false;

		if(!is_match) printf("not match\n");
		else {
			for(i=0; i<res_cnt; i+=2) {
				printf("%d %d\n", res[i], res[i+1]);
			}
		}
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}