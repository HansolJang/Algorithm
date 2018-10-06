#include <cstdio>
#include <cstring>
#define QSIZE 10000001
using namespace std;

int n, d, k, l;
bool fans[QSIZE];

int main() {
	scanf("%d %d %d %d",&n, &d, &k, &l);
	memset(fans, true, sizeof(fans));
	fans[0] = false;

	int start = d == 1 ? 2 : n;
	for(int i = 0; i < n; i++) {
		int step = k % (n - i) == 0 ? (n - i) : k % (n - i);
		int cur = 0;
		while(true) {
			start %= n;
			if(start == 0) start = n;
			if(fans[start] == true) {
				cur++;
				if(cur == step) break;
			}
			if(d == 1) start++;
			else start--;
		}
		printf("step %d, next %d\n", step, start);
		fans[start] = false;
		k += l;
		if(i == n - 1) printf("%d\n", start);
	}
	return 0;
}