////scpc2회 5번문제 구두제작
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int schedule[101];
pair<int, int> aftime[201];	
int rem_proc[201];
int n, k, deadline;
bool finished;
void make_shoes(int sec) {
	if(sec == deadline + 1) {
		bool tmp = true;
		for(int i=1; i<=n; i++) {
			if(rem_proc[i] > 0) {
				tmp = false;
				break;
			}
		}
		finished |= tmp;
		return;
	}
	if(schedule[sec] <= 0) {
		make_shoes(sec + 1);
		return;
	}
	for(int i=1; i<=n; i++) {
		if(rem_proc[i] > 0 &&
			aftime[i].first <= sec && aftime[i].second >= sec) {
			schedule[sec] -= 1;
			rem_proc[i] -= 1;
			make_shoes(sec + 1);
			schedule[sec] += 1;	
			rem_proc[i] += 1;
		}
	}
}
int main(int argc, char** argv) {
	setbuf(stdout, NULL);
	int T, i, j, a, f, p, s, e;
	int test_case;
	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		finished = false;
		deadline = 0;
		memset(schedule, 0, sizeof(schedule));
		memset(rem_proc, 0, sizeof(rem_proc));
		scanf("%d %d", &n, &k);
		for(i=1; i<=n; i++) {
			scanf("%d %d %d", &a, &f, &p);
			if(f - a == p) {
				for(j=a; j<=f; j++)
					schedule[j]--;
				rem_proc[i] = 0;
				continue;
			}
			aftime[i] = make_pair(a, f);
			rem_proc[i] = p;
		}
		for(i=0; i<k; i++) {
			scanf("%d %d", &s, &e);
			deadline = max(deadline, e);
			for(j=s; j<=e; j++)
				schedule[j]++;
		}
		make_shoes(0);
		printf("Case #%d\n", test_case);
		printf("%d\n", finished);
	}
	return 0;
}

/*
sample input:
2
3 2
0 4 3
1 3 2
2 7 4
0 7
2 4
3 2
0 4 3
1 3 2
1 6 4
0 7
2 4

sample output:
1
0
*/