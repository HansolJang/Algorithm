/*

VC, GCC에서 사용

*/

#include <stdio.h>

// typedef struct stack
// {
// 	int top;
// 	int data[88888];
// } stack;

// void push(stack* st, int data) {
// 	if(st->top == 88887) return;
// 	st->data[++st->top] = data;
// }

// int pop(stack* st) {
// 	return st->data[st->top--];
// }

// int top(stack* st) {
// 	return st->data[st->top];
// }

// bool is_empty(stack* st) {
// 	if(st->top < 0) return true;
// 	else return false;
// }

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	long long height[88888][2];
	int num;
	int i;
	int index;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{	

		printf("#testcase%d\n",itr+1);
		scanf("%d", &num);
		stack st;
		st.top = -1;
		int cnt[num][2];
		int sum = 0;
		
		for(i=0; i<num; i++) {
			scanf("%lld", &height[i]);
			cnt[i][0] = 0; //초기화
			// printf("%lld\n", height[i]);
		}

		for(i=1; i<num+1; i++) {
			index = num - i;
			while(1) {
				if(is_empty(&st)) {
					push(&st, height[index]);
					break;
				} else {
					// printf("height : %d, top: %d\n", height[i], top(&st));
					if(height[index] > top(&st)) {
						//while pop
						cnt[index][0]++;  //가중치
						cnt[index][1] = height[i]; //소값
						for(int j=0; j<num; j++) {
							if(cnt[j][1] == top(&st))
								cnt[index][0] += cnt[j][0];
						}
						pop(&st);
						// for(int k=0; k<num; k++) {
						// 	printf("%d ", cnt[k][0]);
						// }
						// printf("\n");				

					} else {
						push(&st, height[index]);
						break;
					}
				}
			}
		} //for

		for(i=0; i<num; i++) {
			sum += cnt[i][0];
		}
		printf("%d\n", sum);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}