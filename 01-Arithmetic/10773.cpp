//https://www.acmicpc.net/problem/10773
#include <cstdio>
using namespace std;
int arr[100001];

int main() {
	int k, n, head = 0;
	int ans = 0;
	scanf("%d", &k);
	for(int i = 0; i < k; i++) {
		scanf("%d", &n);
		if(n == 0) ans -= arr[--head];
		else ans += arr[head++] = n;
	}
	printf("%d\n", ans);
	return 0;
}