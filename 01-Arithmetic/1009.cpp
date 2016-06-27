//https://www.acmicpc.net/problem/1009
#include <cstdio>
#include <vector>
#include <memory.h>
using namespace std;
int main() {
	int tcase, a, b, t, i;
	int cnt[10] = {1, 1, 4, 4, 2, 1, 1, 4, 4, 2}; // 거듭제곱의 1의 자리가 반복되는 횟수
	scanf("%d", &tcase);
	while(tcase--) {
		scanf("%d %d", &a, &b);
		a %= 10;
		b = ((b % cnt[a]) + cnt[a] - 1) % cnt[a]; // 0~3, 반복되는 몇번째 수인지
		t = a;
		for(i = 0; i < b; i++)
			t *= a;
		printf("%d\n", a == 0 ? 10 : t % 10); // 예외 : 10의 배수일 경우, 10
	}
	return 0;
}