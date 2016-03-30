//https://www.codeground.org/practice/practiceProbView.do?probId=2
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	setbuf(stdout, NULL);
	int TC, test_case, ans, N, i, goldScore, subScore;
	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		scanf("%d", &N);
		vector<int> score(N);
		for (i = 0; i < N; i++)
			scanf("%d", &score[i]);
		sort(score.begin(), score.end());
		ans = 0;
		subScore = 0;
		for (i = 0; i < N; i++) {
			subScore = max(subScore, score[i] + N - i);
		}
		for (i = 0; i < N; i++) {
			goldScore = score[i] + N;
			if (goldScore >= subScore)
				ans++;
		}
		printf("Case #%d\n", test_case);
		printf("%d\n", ans);
	}
	return 0;
}