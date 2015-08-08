#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>


int comstr(const void *a, const void *b)
{
	return (strcmp((char*)a, (char*)b));
}

int comchar(const void *a, const void *b)
{
	return *(char*)a - *(char*)b;
}

int comint(const void *a, const void *b)
{
	return ((*(int*)a) - (*(int*)b));
}


int main()
{
	//string sort
	char str[5][10] = {"hamburger","beer","banana", "computer", "apple"};

	qsort(str, 5, sizeof(str[0]), comstr);

	for(int j=0; j<5; j++)
	{
		printf("%d %s\n", j, str[j]);
	}

	// //int sort
	// int arr[10] = {5,2,7,2,8,1,9,4,10,3};
	// qsort(arr, 10, sizeof(int), comint);
	// for(int i=0; i<10; i++)
	// {
	// 	printf("%d ", arr[i]);
	// }
	// printf("\n");

	// //char sort
	// char carr[5] = {'w', 'a', 'b','f', 's'};
	// qsort(carr, 5, sizeof(char), comchar);
	// for(int i=0; i<5; i++)
	// {
	// 	printf("%c ", carr[i]);
	// }
	// printf("\n");

	// int key = 3;
	// int *ptr = (int*)bsearch(&key, arr, 10, sizeof(int), comint);
	// printf("arr[%d] = %d",(ptr-arr), arr[ptr-arr]);

	char key[10] = "computer";
	int *ptr = (int*)bsearch(&key, str, 5, sizeof(str[0]), comstr);
	printf("%s %d\n", str[ptr-(int*)str], ptr-(int*)str);

	for(int i=0; i<10; i++)
	{
		printf("%s\n", str[i]);
	}


	return 0;
}