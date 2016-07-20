//https://www.acmicpc.net/problem/3015
#include <cstdio>
#include <stack>
using namespace std;
int height[500000];
int main() {
	int n;
	long long ans = 0;
	stack<pair<int, int> > s;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &height[i]);
	for(int i=0; i<n; i++) {
		pair<int, int> p = make_pair(height[i], 1);
		while(!s.empty()) {
			if(s.top().first <= p.first) {
				ans += s.top().second;
				if(s.top().first == p.first)
					p.second += s.top().second;
				s.pop();
			}
			else
				break;
		}
		if(!s.empty())
			ans += 1;
		s.push(p);
	}
	printf("%lld\n", ans);
	return 0;
}