// https://www.acmicpc.net/problem/1094
#include <cstdio>
using namespace std;

int main() {
	int x;
	scanf("%d", &x);
	int stick = 0;
	while(x > 0) {
		stick += x % 2;
		x /= 2;
	}
	printf("%d\n", stick);
}