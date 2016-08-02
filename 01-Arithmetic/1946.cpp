//https://www.acmicpc.net/problem/1946
#include <cstdio>
using namespace std;
int score[100001];
int main() {
	int tc, n, paper, intv, ans, tmp;
	scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%d %d", &paper, &intv);
			score[paper] = intv;
		}
		ans = 1;
		tmp = score[1];
		//인덱스 = 서류순위 이므로 현재 i는 안되는 상황. 면접도 i보다 잘본사람이 있으면 못	뽑힘.
		//tmp = 내 앞사람들 중에 면접 가장 잘 본 사람의 순위
		for(int i=1; i<=n; i++) {
			if(score[i] < tmp) {
				tmp = score[i];
				ans += 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}