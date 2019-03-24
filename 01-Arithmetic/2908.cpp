// https://www.acmicpc.net/problem/2908
#include <cstdio>
using namespace std;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	a = a - (a / 100 * 100) + (a % 10 * 100) - a % 10 + a / 100;
	b = b - (b / 100 * 100) + (b % 10 * 100) - b % 10 + b / 100;
	printf("%d\n", a > b ? a : b);
	return 0;
}
