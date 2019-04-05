#include <cstdio>
using namespace std;

bool prime[10001] = {false, };

int main() {
	bool temp = true;
	for (int i = 2; i < 10001; i++) {
			temp = true;
		for (int j = 2;; j++) {
			if (j * j > i) break;
			if (i % j == 0) {
				temp = false;
				break;
			}
		}
		if (temp) prime[i] = true;
	}
	int n, num, ans1, ans2;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &num);
		for(int j = 2; j < num / 2 + 1; j++) {
			if (prime[j] && prime[num - j]) {
				ans1 = j;
				ans2 = num - j;
			}
		}
		printf("%d %d\n", ans1, ans2);
	}
	return 0;	
}