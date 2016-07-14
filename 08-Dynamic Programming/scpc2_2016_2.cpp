#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int pfee[10001];
int qfee[10001];
int cache[10001];
int n;
//week주의 최대 수입 리턴
int solve(int week) {
	if(week < 1)
		return 0;
	if(week == 1)
		return max(pfee[1], qfee[1]);
	if(cache[week] != -1)
		return cache[week];
	cache[week] = 0;
	cache[week] = max(cache[week], pfee[week] + solve(week - 1));
	cache[week] = max(cache[week], qfee[week] + solve(week - 2));
	return cache[week];	
}
int main(int argc, char** argv) {
	setbuf(stdout, NULL);
	int T, test_case, i;
	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		memset(cache, -1, sizeof(cache));
		scanf("%d", &n);
		for(i=1; i<=n; i++)
			scanf("%d", &pfee[i]);
		for(i=1; i<=n; i++)
			scanf("%d", &qfee[i]);
		printf("Case #%d\n", test_case);
		printf("%d\n", solve(n));
	}
	return 0;
}