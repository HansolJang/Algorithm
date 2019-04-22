#include <cstdio>
using namespace std;
int main() {
	long long a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	long long mul = a * b * c;
	int ans[10] = {0, };
	while(mul > 0) {
		ans[mul % 10]++;
		mul /= 10;
	}
	for(int i = 0; i < 10; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}