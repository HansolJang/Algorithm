//https://www.acmicpc.net/problem/11812
#include <cstdio>
using namespace std;
long long n, x, y;
int k, q, cnt;
int main() {
	scanf("%lld %d %d", &n, &k, &q);
	for(int i=0; i<q; i++) {
		scanf("%lld %lld", &x, &y);
		cnt = 0;
		while(x != y) {
			if(x > y) {
				x = (x + k - 2) / k;
				cnt += 1;
			}
			else {
				y = (y + k - 2) / k;
				cnt += 1;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}