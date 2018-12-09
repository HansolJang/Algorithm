//https://www.acmicpc.net/problem/2439
#include <cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < n; j++) {
			printf("%s", i + j >= n ? "*" : " ");
		}
		printf("\n");
	}
	return 0;
}