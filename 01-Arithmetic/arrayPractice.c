#include <stdio.h>

void function(int *temp)
{
	temp[4] = 5;
}

int main()
{
	int array[5][5];

	function(&(array[0][0]));

	printf("array[0][4] = %d\n", array[0][4]);

	return 0;
}