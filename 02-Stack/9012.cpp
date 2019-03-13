//https://www.acmicpc.net/problem/6549
#include <cstdio>
#include <stack>
using namespace std;
int main() {
	int n;
	char input[51];
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		stack<char> s;
		scanf("%s", input);
		for(int j = 0;; j++) {
			if(input[j] == '\0')
				break;
			if(input[j] == '(')
				s.push('(');
			if(input[j] == ')') {
				if(s.empty()) {
					s.push(')');
					break;
				}
				else s.pop();
			}
		}
		printf("%s\n", s.empty() ? "YES" : "NO");
	}
	return 0;
}