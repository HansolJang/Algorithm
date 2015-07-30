#include <stdio.h>

void swap(int* arr, int idx1, int idx2);
int partition(int* arr, int left, int right);
void quickSort(int* arr, int left, int right);

int main() {
	int arr[10] = {7, 18, 3, 1, 24, 183, 4, 9,33, 57};

	printf("before : ");
	for(int i=0; i<10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	quickSort(arr, 0, 9);

	printf("after : ");
	for(int i=0; i<10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

void swap(int* arr, int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp; 
}

/*
left, right, low, high, pivot
1. low가 high가 넘어설때까지 반복
 	low는 피봇보다 큰 값을 찾을 때까지
 	high는 피봇보다 작은 값을 찾을 때까지
	-> 둘다 찾았으면 swap
2. 1번 탈출하면 high와 pivot swap

*/
int partition(int* arr, int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while(!(low > high))
	{
		// 피봇보다 큰 값을 찾을 때까지
		while(!(arr[low] >= pivot))
		{
			low++;
		}

		// 피봇보다 작은 값을 찾을 때까지
		while(!(arr[high] <= pivot))
		{
			high--;
		}

		if(low <= high)
		{
			swap(arr, low, high);
		}
	}

	//피봇의 위치를 찾았으니 swap
	swap(arr, left, high);
	return high;  //피봇의 고정된 인덱스 반환
}

/*
파티션 함수를 사용하여 두부분으로 나눈뒤 다시 퀵소트 재귀호출
*/
void quickSort(int* arr, int left, int right)
{
	if(left <= right)
	{
		int pivot = partition(arr, left, right);
		quickSort(arr, left, pivot - 1);
		quickSort(arr, pivot + 1, right);
	}
}