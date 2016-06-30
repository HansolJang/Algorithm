//https://www.acmicpc.net/problem/6549
#include <cstdio>
#include <stack>
using namespace std;
long long h[100001];
int main() {
	int n, right, left;
	long long ans, height;
	while(true) {
		scanf("%d", &n);
		if(n == 0) break;
		stack<long long> s;
		ans = 0;
		for(int i=0; i<n; i++) {
			scanf("%lld", &h[i]);
			//현재 막대가 top보다 작으면 top의 최대 넓이(t) 구하기
			while(!s.empty() && h[s.top()] > h[i]) {
				right = i;
				height = h[s.top()]; //height, 현재의 기준
				s.pop();
				s.empty() ? left = 0 : left = s.top() + 1;
				if(ans < height * (right - left))
					ans = height * (right - left);
			}
			s.push(i);
		}
		//스택에 남은 막대 검사
		while(!s.empty()) {
			right = n;
			height = h[s.top()];
			s.pop();
			s.empty() ? left = 0 : left = s.top() + 1;
			if(ans < height * (right - left))
				ans = height * (right - left);
		}
		printf("%lld\n", ans);
	}
	return 0;
}