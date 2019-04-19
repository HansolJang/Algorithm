#include <cstdio>
#include <cstdlib>
using namespace std;

int n, m;
int arr[500001];
int dest[500001];

int ascint(const void *a, const void *b) {
	return ((*(int*)a) - (*(int*)b));
}

int bsearch(int num) {
	int pivot = n / 2;
	int left = 0;
	int right = n - 1;
	printf("%d pivot = %d, left = %d, right = %d\n", num, arr[pivot], arr[left], arr[right]);
	while(left <= right) {
		if (num < arr[left] || num > arr[right])
			return 0;
		if (arr[pivot] == num || arr[left] == num || arr[right] == num)
			return 1;
		if (arr[pivot] > num)
			left = pivot + 1;
		else right = pivot - 1;
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &dest[i]);
	}
	qsort(arr, n, sizeof(int), ascint);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (int i = 0; i < m; i++) {
		printf("%d ", bsearch(dest[i]));
	}
	printf("\n");
	return 0;
}