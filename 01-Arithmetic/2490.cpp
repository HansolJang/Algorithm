#include <cstdio>
using namespace std;
int main() {
	int a, b, c, d, sum;
	char score[6] = "DCBAE";
	for(int i = 0; i < 3; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		sum = a + b + c + d;
		printf("%c\n", score[sum]);
	}
	return 0;
}