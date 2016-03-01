#include <stdio.h>
#include <memory.h>
#include <string.h>

int stack[11111];
int nCount;
int itr;
int top;
char operand[11];

int main() {
	scanf("%d", &nCount);
	top = -1;

	for(itr=0; itr<nCount; itr++) {
		scanf("%s", &operand);

		if(!strcmp(operand, "push")) {
			int data;
			scanf("%d", &data);
			stack[++top] = data;
		}
		else if(!strcmp(operand, "top")) {
			if(top == -1) {
				printf("-1\n");
			} else {
				printf("%d\n", stack[top]);
			}
		}
		else if(!strcmp(operand, "size")) {
			printf("%d\n", top + 1);
		}
		else if(!strcmp(operand, "pop")) {
			if(top == -1) printf("-1\n");
			else printf("%d\n", stack[top--]);
		}
		else if(!strcmp(operand, "empty")){
			if(top == -1) printf("1\n");
			else printf("0\n");
		}

	}
}