#include <stdio.h>
#include <stdlib.h>

/*
	9개의 숫자중 7개의 합이 100이 되는 수를 찾아 정렬하여 출력
	모든합은 무조건 100이 넘음 -> 100을 빼면 2수의 합이 나옴
	해당하는 수를 찾아 뺀 후 정렬
*/

int compare(const void *first, const void *second) {
	if(*(int *)first > *(int *)second) 
		return 1;
	else if(*(int *)first < *(int *)second)
		return -1;
	else
		return 0;
}

int main(){
	int arr[10];
	int i;
	int sum;
	int iarr[9];
	int res[7];
	for(i=0; i<9; i++) {
		scanf("%d\n", &arr[i]);
	}

	while(sum != 100) {
		sum = 0;
		for(i=0; i<9; i++) {
			iarr[i] = 0;
		}
		while(sizeof(res)/sizeof(int) < 7) {
			int r = rand()%9;
			if(iarr[r] == 0) {
				iarr[r] = 1;
				sum += arr[r];
				res.add(arr[r]);
			}
			else continue;
		}
	}

	// 정렬
	qsort(res, 7, sizeof(int), compare);
	
	for(i=0; i<7; i++) {
		printf("%d ", res[i]);
	}
	return 0;
}