//https://www.acmicpc.net/problem/7568
#include <cstdio>
#include <utility>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	pair<int, int> p[n];
	int a, b;
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		p[i] = make_pair(a, b);
	}
	int count;
	for(int i = 0; i < n; i++) {
		count = 0;
		for(int j = 0; j < n; j++) {
			if(i == j) continue;
			if(p[i].first < p[j].first && p[i].second < p[j].second) {
				count++;
			}
		}
		printf("%d ", count + 1);
	}
	printf("\n");
	return 0;
}