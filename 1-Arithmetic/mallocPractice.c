#include <stdio.h>
#include <stdlib.h>

int main() {
	int size;
	int *arr;
	size = scanf("%d\n", &size);
	arr = (int *)malloc(sizeof(int) * size );
	free(arr);
	return 0;
}
