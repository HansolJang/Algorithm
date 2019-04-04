#include <cstdio>
using namespace std;

int n;
int cache[100001][3];
int result;

int main(void) {
	scanf("%d", &n);
	cache[0][0] = 1;
	cache[0][1] = 1;
	cache[0][2] = 1;

	for (int i = 1; i < n; i++) {
		cache[i][0] = (cache[i - 1][0] + cache[i - 1][1] + cache[i - 1][2]) % 9901;
		cache[i][1] = (cache[i - 1][0] + cache[i - 1][2]) % 9901;
		cache[i][2] = (cache[i - 1][0] + cache[i - 1][1]) % 9901;
	}
	for (int i = 0; i < 3; i++) {
		result += cache[n-1][i];
	}
    
    printf("%d\n", result % 9901);
	return 0;
}