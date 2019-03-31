//https://www.acmicpc.net/problem/1193
#include <cstdio>
using namespace std;

int main() {
	int x;
	scanf("%d", &x);
	int idx = 0;
	for(int i = 1;; i++) {
		if (idx + i >= x) {
			printf("%d/%d\n", 
				i % 2 == 0 ? x - idx ? i - x - idx + 1, 
				i % 2 == 0 ? i - x - idx + 1 : x - idx);
			break;
		}
		idx += i;
	}
	return 0;
}