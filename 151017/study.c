#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int num_subject;
int num_select;
int score[222222];
int max;

// void swap(int *arr, int idx1, int idx2);
// int partition(int *arr, int left, int right);
// void quickSort(int *arr, int left, int right);
int compare (const void *first, const void *second)
{
    if (*(int*)first > *(int*)second)
        return -1;
    else if (*(int*)first < *(int*)second)
        return 1;
    else
        return 0;
}

int main(void) {
	int T;
	int test_case;

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		memset(score, 0, sizeof(score));
		max = 0;
		scanf("%d %d", &num_subject, &num_select);
		for(int i=0; i<num_subject; i++)
		{
			scanf("%d", &score[i]);
		}

		// quickSort(score, 1, num_subject);
		qsort(score, num_subject, sizeof(int), compare);

		
		for(int i=0; i<num_select; i++)
		{
			max += score[i];
		}			

		printf("Case #%d\n", test_case);
		printf("%d\n", max);
        
	}

	return 0;	//	정상종료 시 반드시 0을 리턴해야 합니다.
}


// void swap(int *arr, int idx1, int idx2)
// {
// 	int temp = arr[idx1];
// 	arr[idx1] = arr[idx2];
// 	arr[idx2] = temp;
// }

// int partition(int *arr, int left, int right)
// {
// 	int pivot = arr[1];
// 	int low = left + 1;
// 	int high = right;

// 	while(low <= high)
// 	{
// 		while(pivot <= arr[low])
// 		{
// 			low++;
// 			if(low > high)
// 				break;
// 		}

// 		while(pivot > arr[high])
// 		{
// 			high--;
// 			if(low > high)
// 				break;
// 		}

// 		if(low <= high)
// 			swap(arr, low, high);
// 	}

// 	swap(arr, left, high);
// 	return high;
// }

// void quickSort(int *arr, int left, int right)
// {
// 	if(left <= right)
// 	{
// 		int pivot = partition(arr, left, right);
// 		quickSort(arr, left, pivot - 1);
// 		quickSort(arr, pivot + 1, right);
// 	}
// }