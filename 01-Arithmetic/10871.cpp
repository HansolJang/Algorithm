#include <cstdio>
using namespace std;

int main() {
	int n, b, t, ans = 0;
	scanf("%d %d", &n, &b);
	for(int i = 0; i < n; i++) {
		scanf("%d", &t);
		if(b > t) printf("%d ", t);
	}
	printf("\n");
	return 0;
}