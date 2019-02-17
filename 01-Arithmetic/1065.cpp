//https://www.acmicpc.net/problem/1065
#include <cstdio>
using namespace std;

int main() {
	int n, ans = 0;
	scanf("%d", &n);
	if(n < 100) {
		printf("%d\n", n);
		return 0;
	}
	for(int i = 100; i <= n; i++) {
		if((i%10-i/10%10) == (i/10%10-i/100)) ans++;
	}
	printf("%d\n", ans+99);
	return 0;
}