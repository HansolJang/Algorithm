#include <cstdio>
using namespace std;

void swap(int* arr, int idx1, int idx2);
int partition(int* arr, int left, int right);
void qusort(int* arr, int left, int right);

int main() {
	int arr[10] = {5, 2, 8, 1, 4, 3, 7, 10, 9, 0};
	for(int i=0; i<10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	qusort(arr, 0, 9);
}

void swap(int* arr, int idx1, int idx2) {
	int tmp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = tmp;
}
int partition(int* arr, int left, int right) {
	int pivot = arr[left];
	int low = left + 1;
	int high = right;
	while(!(low > high)) {
		while(pivot >= arr[low])
			low++;
		while(pivot < arr[high])
			high--;
		if(low <= high)
			swap(arr, low, high);
		printf("%d\n", high);
	}
	swap(arr, left, high);
	printf("left:%d right:%d\n", left, right);
	for(int i=0; i<10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return high;
}
void qusort(int* arr, int left, int right) {
	if(left <= right) {
		int pivot = partition(arr, left, right);
		qusort(arr, left, pivot - 1);
		qusort(arr, pivot + 1, right);
	}
}