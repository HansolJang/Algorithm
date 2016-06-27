//https://www.acmicpc.net/problem/2056
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int N;
vector<int> todo[10001];
int work[10001];
int prework[10001];
int stwork[10001] = {0, };
queue<pair<int, int> > q;
int main() {
	int t, fwork, ftime, ans = 0;
	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		scanf("%d %d", &work[i], &prework[i]);
		if(prework[i] == 0) {
			q.push(make_pair(i, work[i]));
		} else {
			for(int j=1; j<=prework[i]; j++) {
				scanf("%d", &t);
				todo[t].push_back(i);
			}
		}	
	}
	while(!q.empty()) {
		fwork = q.front().first;
		ftime = q.front().second;
		ans = max(ans, ftime);
		q.pop();
		t = todo[fwork].size();
		for(int i=0; i<t; i++) {
			stwork[todo[fwork][i]] = max(stwork[todo[fwork][i]], ftime);
			if(--prework[todo[fwork][i]] == 0)
				q.push(make_pair(todo[fwork][i], stwork[todo[fwork][i]] + work[todo[fwork][i]]));
		}
	}
	printf("%d\n", ans);
	return 0;
}