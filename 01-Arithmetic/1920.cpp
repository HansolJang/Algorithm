//https://www.acmicpc.net/problem/1920
#include <cstdio>
#include <map>
using namespace std;
int main() {
	int n, m, x;
	map<int, int> cnt;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &x);
		cnt[x] = 1;
	}
	scanf("%d", &m);
	for(int i=0; i<m; i++) {
		scanf("%d", &x);
		printf("%d\n", cnt[x]);
	}
	return 0;
}