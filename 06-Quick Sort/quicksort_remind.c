#include <stdio.h>

void swap(int* arr, int idx1, int idx2);
int partition(int* arr, int left, int right);
void quickSort(int* arr, int left, int right);
bool binarySearch(int num, int left, int right);
int arr[] = {4,2,7,7,4,9,12,3,1,10};

int main() { 
	int arr2[] = {1,5,8,9,10,3};
	quickSort(arr, 0, 9);
	for(int i=0; i<10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	for(int i=0; i<6; i++) {
		printf("%d %d\n",arr2[i] ,binarySearch(arr2[i], 0, 9));
	}
	return 0;
}

void swap(int* arr, int idx1, int idx2) {
	if(idx1 != idx2) {
		arr[idx1] = arr[idx1] + arr[idx2];
		arr[idx2] = arr[idx1] - arr[idx2];
		arr[idx1] = arr[idx1] - arr[idx2];
	}
}

int partition(int* arr, int left, int right) {
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while(low <= high) {
		while(pivot >= arr[low]) {
			low++;
			if(low > high) break;
		}

		while(pivot < arr[high]) {
			high--;
			if(low > high) break;
		}
		if(low < high) swap(arr, low, high);
	}
	swap(arr, left, high);
	for(int i=0; i<10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return high;
}

void quickSort(int* arr, int left, int right) {
	if(left <= right) {
		int pivot = partition(arr, left, right);
		quickSort(arr, left, pivot - 1);
		quickSort(arr, pivot + 1, right);
	}
}

bool binarySearch(int num, int left, int right) {
	if(arr[left] > num || arr[right] < num)	
		return false;
	if(left > right)
		return false;
	int mid = (left + right) / 2;
	if(arr[mid] == num)
		return true;
	else if(arr[mid] > num)
		return binarySearch(num, left, mid - 1);
	else if(arr[mid] < num)
		return binarySearch(num, mid + 1, right);
}