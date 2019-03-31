//https://www.acmicpc.net/problem/1085
#include <cstdio>
using namespace std;

int main() {
	int w, h, x, y;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	int maxx = w - x < x ? w - x : x;
	int maxy = h - y < y ? h - y : y;
	printf("%d\n", maxx < maxy ? maxx : maxy);
}