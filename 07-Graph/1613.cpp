//https://www.acmicpc.net/problem/1613
#include <cstdio>
using namespace std;
bool event[401][401];
int main() {
	int n, K, e1, e2, s;
	scanf("%d %d", &n, &K);
	while(K--) {
		scanf("%d %d", &e1, &e2);
		event[e1][e2] = true;
	}
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				event[i][j] |= event[i][k] & event[k][j];
			}
		}
	}
	scanf("%d", &s);
	while(s--) {
		scanf("%d %d", &e1, &e2);
		if(event[e1][e2]) printf("-1\n");
		else if(event[e2][e1]) printf("1\n");
		else printf("0\n");
	}
	return 0;
}