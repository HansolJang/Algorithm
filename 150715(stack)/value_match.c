/*

VC, GCC에서 사용

*/

#include <stdio.h>

typedef struct stack{
	int top;
	int data[33];
}stack;

void push(stack* st, int data) {
	if(st->top == 32) return;
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
	char input[33];
	int i;
	bool con; //한 괄호가 계속됨을 표시할 플래그
	int sum, temp; // sum은 수식전체의 값, temp는 한 괄호가 끝날때까지의 값
	char pre;  //직전문자
	bool is_match;
	// bool is_end; //연산 하나가 끝났는지 여부

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		// 초기화
		for(i=0; i<33; i++) {
			input[i] = -1;
		}
		stack st;
		st.top = -1;
		sum = 0;
		// temp = 1; // 곱해져야하므로 
		is_match = true;
		// is_end = true;


		// 입력값 받기
		scanf("%s", &input);

		for(i=0; i<33; i++) {

			switch(input[i]){
				case '(':					
					//push	
					push(&st, -1);
					break;
				case ')':
					if(top(&st) == -1) {
						pop(&st);
						push(&st, 2); // 결과
					} else if (top(&st) == -2){
						is_match = false;
						break;
					} else {
						// top(&st) > 0
						sum = 0;
						while(1) {
							if(top(&st) == -1) {
								sum *= 2;
								pop(&st);
								push(&st, sum);
								break;
							} else {
								sum += pop(&st);
							}
						}
					}
					break;
				case '[':
					//push					
					push(&st, -2);
					break;
				case ']':
					if(top(&st) == -2) {
						pop(&st);
						push(&st, 3); // 결과
					} else if (top(&st) == -1){
						is_match = false;
						break;
					} else {
						// top(&st) > 0
						sum = 0;
						while(1) {
							if(top(&st) == -2) {
								sum *= 3;
								pop(&st);
								push(&st, sum);
								break;
							} else {
								sum += pop(&st);
							}
						}
					}
					break;
			} // switch
		} //for

		sum = 0;
		while(1) {
			if(!is_empty(&st)) {
				if(top(&st) > 0) {
					sum += pop(&st);
				} else {
					is_match = false;
					break;
				}
			} else break;
		}

		if(is_match) printf("%d\n", sum);
		else printf("%d\n", 0);
		
	} //testcase

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}