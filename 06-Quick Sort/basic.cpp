#include <cstdio>
using namespace std;

void swap(int* arr, int idx1, int idx2);
int partition(int* arr, int left, int right);
void qusort(int* arr, int left, int right);
bool bisearch(int num);
int arr[10] = {5, 2, 8, 1, 4, 3, 7, 10, 9, 0};
	
int main() {
	for(int i=0; i<10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	qusort(arr, 0, 9);
	for(int i=0; i<10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("10? %d\n", bisearch(10));
	printf("6? %d\n", bisearch(6));
	printf("8? %d\n", bisearch(8));
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
	while(low <= high) {
		while(pivot >= arr[low])
			low++;
		while(pivot < arr[high])
			high--;
		if(low <= high)
			swap(arr, low, high);
	}
	swap(arr, left, high);
	return high;
}
void qusort(int* arr, int left, int right) {
	if(left <= right) {
		int pivot = partition(arr, left, right);
		qusort(arr, left, pivot - 1);
		qusort(arr, pivot + 1, right);
	}
}

bool bisearch(int num) {
	int pivot = 5; // N/2
	int left = 0; // left
	int right = 9; // right
	if(num > arr[right] || num < arr[left])
		return false;
	while(left <= right) {
		if(num == arr[left] || num == arr[right] || num == arr[pivot])
			return true;
		if(num > arr[pivot])
			left = pivot + 1;
		else
			right = pivot - 1;
		pivot = (left + right) / 2;
	}
	return false;
}