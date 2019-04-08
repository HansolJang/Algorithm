// https://www.acmicpc.net/problem/1026
#include <cstdio>
#include <cstdlib>
using namespace std;

int ascint(const void *a, const void *b) {
	return ((*(int*)a) - (*(int*)b));
}

int descint(const void *a, const void *b) {
	return ((*(int*)b) - (*(int*)a));
}

int main() {
	int a[51];
	int b[51];
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	qsort(a, n, sizeof(int), ascint);
	qsort(b, n, sizeof(int), descint);
	int result = 0;
	for(int i = 0; i < n; i++) {
		result += a[i] * b[i];
	}
	printf("%d\n", result);
	return 0;
}