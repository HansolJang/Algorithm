//https://www.acmicpc.net/problem/9466
#include <cstdio>
#include <cstring>
using namespace std;
#define START 0
#define ORDER 1 
int edge[100001], check[100001][2];
int main() {
	int tc, n, ans, target, order;
	scanf("%d", &tc);
	while(tc--) {
		memset(edge, 0, sizeof(edge));
		memset(check, 0, sizeof(check));
		scanf("%d", &n);
		ans = n;
		for(int i=1; i<=n; i++) 
			scanf("%d", &edge[i]);
		for(int i=1; i<=n; i++) {
			if(check[i][START]) continue;
			order = 1;
			check[i][START] = i; check[i][ORDER] = order;
			target = edge[i];
			while(!check[target][START]) {
				check[target][START] = i;
				check[target][ORDER] = ++order;
				target = edge[target];
			}
			if(check[target][START] == i)
				ans -= (++order - check[target][ORDER]);
		}
		printf("%d\n", ans);
	}
	return 0;
}