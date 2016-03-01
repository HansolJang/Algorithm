/*
https://www.acmicpc.net/problem/2776
*/
#include <stdio.h>

void swap(int* arr, int idx1, int idx2);
int partition(int* arr, int left, int right);
void quickSort(int* arr, int left, int right);
bool binarySearch(int num, int left, int right);

int N;
int M;
int diary1[1111111];
int diary2[1111111];

int main(){
	int nCount;
	int itr;

	scanf("%d", &nCount);

	for(itr=0; itr<nCount; itr++){
		for(int i=0; i<1111111; i++){
			diary2[i] = -1;
			diary1[i] = -1;
		}
		scanf("%d", &N);
		for(int i=1; i<=N; i++){
			scanf("%d", &diary1[i]);
		}
		scanf("%d", &M);
		for(int j=1; j<=M; j++){
			scanf("%d", &diary2[j]);
		}

		quickSort(diary1, 1, N);

		for(int i=1; i<=M; i++){
			printf("%d\n", binarySearch(diary2[i], 1, M));
		}
	}

	return 0;
}

bool binarySearch(int num, int left, int right){
	// printf("%d %d %d\n", num, left, right);
	if(num > diary1[right] || num < diary1[left]){
		return false;
	}

	if(left > right){
		return false;
	}

	int mid = (left + right) / 2;

	if(diary1[mid] == num){
		return true;
	}
	//왼쪽 선택
	else if(diary1[mid] > num){
		return binarySearch(num, left, mid - 1);
	}
	//오른쪽 선택
	else{
		return binarySearch(num, mid + 1, right);
	}

}

void swap(int* arr, int idx1, int idx2){
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int partition(int* arr, int left, int right){
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while(low <= high){
		while(pivot >= arr[low]){
			low++;

			if(low > high){
				break;
			}
		}
		while(pivot < arr[high]){
			high--;
			if(low > high){
				break;
			}
		}
		if(low <= high){
			swap(arr, low, high);
		}
	}
	swap(arr, left, high);
	return high;
}

void quickSort(int* arr, int left, int right){
	if(left <= right){
		int pivot = partition(arr, left, right);
		quickSort(arr, left, pivot - 1);
		quickSort(arr, pivot + 1, right);
	}
}
