//https://www.acmicpc.net/problem/9935
#include <iostream>
#include <string>
#include <stack>
#include <utility>
using namespace std;

int main() {
	stack< pair<int, int> > st;
	int i, j, slen, exlen, idx = 0;
	bool ismatch;
	string s, ex;
	cin >> s >> ex;
	slen = s.size();
	exlen = ex.size();
	bool unused[slen];
	for(i = 0; i < slen; i++) {
		ismatch = false;
		for(j = 0; j <= idx; j++) {
			if(s[i] == ex[j]) {
				ismatch = true;
				st.push(make_pair(i, j));
				idx = j + 1;
				break;
			}
		}
		if(!ismatch) {
			while(!st.empty())	st.pop();
			idx = 0;
		}
		if(!st.empty() && st.top().second == exlen - 1) {
			for(j = exlen - 1; j >= 0 ; j--) {
				unused[st.top().first] = true;
				st.pop();
			}
			if(st.empty())
				idx = 0;
			else
				idx = st.top().second + 1;
		}
	}
	ismatch = false;
	for(i = 0; i < slen; i++) {
		if(!unused[i]) {
			ismatch = true;
			cout << (char)s[i];
		}
	}
	if(!ismatch)
		cout << "FRULA";
	cout << '\n';
	return 0;
}