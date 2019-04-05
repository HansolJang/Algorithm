// https://www.acmicpc.net/problem/1158
#include <cstdio>
#include <queue>
using namespace std;

int main() {
	int n, m;
	queue<int> q;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		q.push(i);
	}
	printf("<");
	while(!q.empty()) {
		if (q.size() == 1) {
			printf("%d>\n", q.front());
			break;
		}
		for (int i = 1; i < m; i++) {
			q.push(q.front());
			q.pop();
		}
		printf("%d, ", q.front());
		q.pop();
	}
	return 0;
}