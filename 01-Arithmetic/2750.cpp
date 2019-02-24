//https://www.acmicpc.net/problem/2750
#include <cstdio>
using namespace std;

int arr[1001] = {0, };

void swap(int* arr, int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
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
		if(low <= high) swap(arr, low, high);
	}
	swap(arr, left, high);
	return high;
}

void quicksort(int* arr, int start, int end) {
	if(start < end) {
		int pivot = partition(arr, start, end);
		quicksort(arr, start, pivot - 1);
		quicksort(arr, pivot + 1, end);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	quicksort(arr, 0, n - 1);
	for(int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
}
