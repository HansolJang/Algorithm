#include <stdio.h>

int main() {
	int a = 2005;
	int* pA = &a;

	printf("pA : %d\n", pA);
	printf("&a : %d\n", &a);

	(*pA)++;

	printf("a : %d\n", a);
	printf("*pA : %d\n", *pA);

	return 0;
}