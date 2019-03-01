// https://www.acmicpc.net/problem/1003
#include <cstdio>
using namespace std;

int main() {
	int call_zero[41] = {0,};
	int call_one[41] = {0, };
	call_zero[0] = 1;
	call_one[1] = 1;
	for(int i = 2; i < 41; i++) {
		call_zero[i] = call_zero[i - 1] + call_zero[i - 2];
		call_one[i] = call_one[i - 1] + call_one[i - 2];
	}
	int testcase, n;
	scanf("%d", &testcase);
	for(int i = 0; i < testcase; i++) {
		scanf("%d", &n);
		printf("%d %d\n", call_zero[n], call_one[n]);
	}
	return 0;
}