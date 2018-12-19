#include <cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	int max = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if(max < arr[i]) max = arr[i];
	}
	double sum = 0;
	for(int i = 0; i < n; i++) {
		sum += (double) arr[i] / (double) max * 100.0;
	}
	printf("%lf\n", sum / (double) n);
	return 0;
}