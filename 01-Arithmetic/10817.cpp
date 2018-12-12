#include <cstdio>
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int maxnum = max(max(a,b), c);
	printf("%d\n", maxnum == a ? max(b, c) : (maxnum == b ? max(a, c) : max(a, b)));
	return 0;
}
