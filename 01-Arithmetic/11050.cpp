// https://www.acmicpc.net/problem/11050
#include <cstdio>
using namespace std;

int factorial(int num) {
	if (num == 0 || num == 1)
		return 1;
	return factorial(num - 1) * num;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d\n", factorial(n) / (factorial(n - k) * factorial(k)));
	return 0;
}