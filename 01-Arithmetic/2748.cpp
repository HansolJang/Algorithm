#include <cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	long long fibo[100] = {0, };
	fibo[1] = 1;
	for(int i = 2; i < 100; i++) {
		fibo[i] = fibo[i-1] + fibo[i-2];
	}
	printf("%lld\n", fibo[n]);
	return 0;
}