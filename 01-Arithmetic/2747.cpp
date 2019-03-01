// https://www.acmicpc.net/problem/2747
#include <cstdio>
using namespace std;
int main() {
	int answer[46] = {0, };
	answer[1] = 1;
	for(int i = 2; i < 46; i++) {
		answer[i] = answer[i - 1] + answer[i - 2];
	}
	int n;
	scanf("%d", &n);
	printf("%d\n", answer[n]);
	return 0;
}