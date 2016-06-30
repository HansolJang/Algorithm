//scpc2회 1번문제 3N + 1 : 단순구현(에라토스테네스의 체) (만점)
#include <cstdio>
#include <algorithm>
using namespace std;
int appf[64] = {0, };
int num[1140] = {0, };
void start() {
	int t, k;
	for(int i = 1; i<1140; i++) {
		t = 0;
		k = i;
		while(k != 1) {
			if(k % 2 == 0)
				k /= 2;
			else
				k = 3 * k + 1;
			t++;
			if(k < 1140) {
				if(num[k] > 0) {
					t += num[k];
					break;
				}
			}
		}
		num[i] = t;
		if(t < 64) {
			if(appf[t] == 0)
				appf[t] = i;
		}
	}
}
int main(int argc, char** argv) {
	setbuf(stdout, NULL);
	int T, test_case, K;
	start();
	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		scanf("%d", &K);
		printf("Case #%d\n", test_case);
		unsigned long long largest = 1;
		for(int i=0; i<K; i++)
			largest *= 2;
		printf("%d %llu\n", appf[K], largest);
	}
	return 0;
}
